
/*
	Given a positive integer, return its corresponding column title as appear in an Excel sheet.

	For example:

		1 -> A
		2 -> B
		3 -> C
		...
		26 -> Z
		27 -> AA
		28 -> AB 
		...
	Example 1:

	Input: 1
	Output: "A"
	Example 2:

	Input: 28
	Output: "AB"
	Example 3:

	Input: 701
	Output: "ZY"

	https://leetcode.com/problems/excel-sheet-column-title/description/

 */

class Solution {
public:
    string convertToTitle(int n) {
        string strs[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q",
                           "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
        string title = "";
        if (n < 1) {
            return title;
        }
        n--;
        while (n >= 26) {
            title = strs[n % 26] + title;
            n = n / 26;
            n--;
        }
        title = strs[n] + title;
        
        return title;
    }
};