/*

Verdict : Accepted

Complexity Analysis:

Time Complexity: O(1).

The hash map makes the time of get() to be O(1).
The list of double linked nodes make the nodes adding/removal operations O(1).

Space Complexity: O(N).

Where N is Cache Capacity we have used N sized List and Hashmap.

*/

class LRUCache {

	int cachesize;
	list<int>myCache;
	unordered_map<int, pair<int, list<int>::iterator>>hashmap;

public:
	LRUCache(int capacity) {
		cachesize = capacity;
	}

	int get(int key) {

		if (hashmap.find(key) == hashmap.end()) {
			return -1;
		}

		myCache.erase(hashmap[key].second);
		myCache.push_front(key);
		hashmap[key].second = myCache.begin();

		return hashmap[key].first;
	}

	void put(int key, int value) {

		if (hashmap.find(key) != hashmap.end()) {
			myCache.erase(hashmap[key].second);
		}
		else if (myCache.size() == cachesize) {
			hashmap.erase(myCache.back());
			myCache.pop_back();
		}
		myCache.push_front(key);
		hashmap[key] = {value, myCache.begin()};
	}
};
