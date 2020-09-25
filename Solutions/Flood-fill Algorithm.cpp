/*

Method 1 :- Using DFS                                   Verdict :- Accepted

Complexity Analysis :-

Time Complexity: O(P) or O(M*N), where P is the number of pixels in the image and M*N is the dimension of the matrix in
other word we can say M*N = P. We might process every pixel.

Space Complexity: O(P), the size of the implicit call stack when calling dfs.

*/


class Solution {
public:

	void floodFillHelper(vector<vector<int>>& image, int sr, int sc, int myColor, int newColor) {

		if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != myColor) {
			return;
		}

		image[sr][sc] = newColor;

		floodFillHelper(image, sr, sc - 1, myColor, newColor);
		floodFillHelper(image, sr, sc + 1, myColor, newColor);
		floodFillHelper(image, sr - 1, sc, myColor, newColor);
		floodFillHelper(image, sr + 1, sc, myColor, newColor);

	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

		if (image[sr][sc] == newColor) {
			return image;
		}

		int myColor = image[sr][sc];

		floodFillHelper(image, sr, sc, myColor, newColor);

		return image;

	}
};


/*

Method 2 :- Using BFS                                   Verdict :- Accepted

Complexity Analysis :-

Time Complexity: O(P) or O(M*N), where P is the number of pixels in the image and M*N is the dimension of the matrix in
other word we can say M*N = P. We might process every pixel.

Space Complexity: O(P), Extra size for BFS Helper queue .

*/



class Solution {
public:

	void floodFillHelper(vector<vector<int>>&image, int xPos, int yPos, int myColor, int newColor) {
		if (image[xPos][yPos] == newColor) {
			return;
		}

		queue<pair<int, int>>bfsHelper;
		bfsHelper.push({xPos, yPos});

		while (!bfsHelper.empty()) {

			pair<int, int>position = bfsHelper.front();
			bfsHelper.pop();

			int x = position.first;
			int y = position.second;

			if (x < 0 || y < 0 || x >= image.size() || y >= image[0].size() || image[x][y] != myColor) {
				continue;
			}
			else {

				image[x][y] = newColor;
				bfsHelper.push({x, y - 1});
				bfsHelper.push({x, y + 1});
				bfsHelper.push({x - 1, y});
				bfsHelper.push({x + 1, y});
			}
		}
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

		if (image[sr][sc] == newColor) {
			return image;
		}

		int myColor = image[sr][sc];

		floodFillHelper(image, sr, sc, myColor, newColor);

		return image;

	}
};