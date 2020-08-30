/*

Complexity Analysis:

Time complexity: O(Log10(N)). where N is the length of input string and 10 is log base.

Space complexity: O(Log10(N)). Output string will have at most Log10(N) charcters.

*/



/*
KEY IDEA :-

We will be using the array of nubers and sarray of strings to tackle this problem.

Let the number be 74 = LXXIV

let int check[]={1000,900,500,400,100,90,50,40,10,9,5,4,1}
string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"}

check the number which is lesser than equal to 74 which is 50 in the array
50 - L
so we append that into our answer.
ans = L
num=24(74-50)
the number closest to 24 in the array is 10
ans = LX
nums = 14(24-10)
the number closest to 14 is 10 again
ans = LXX
num = 4
ans = LXXIV.

You might be wondering why 4,9 ,40 etc are there in the array.
if 4 wasnt there in the above array it would have been ans = LXXIIII
which is wrong.



*/

class Solution {
public:
	string intToRoman(int num) {

		int numRep[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string romanRep[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

		string output = "";

		for (int i = 0; num != 0 && i <= 12; i++) {
			while (num >= numRep[i]) {
				num = num - numRep[i];
				output += romanRep[i];
			}
		}
		return output;
	}
};
