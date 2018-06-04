/*
	In a string S of lowercase letters, these letters form consecutive groups of the same character.

	For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".

	Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.

	The final answer should be in lexicographic order.

	 

	Example 1:

	Input: "abbxxxxzzy"
	Output: [[3,6]]
	Explanation: "xxxx" is the single large group with starting  3 and ending positions 6.
	Example 2:

	Input: "abc"
	Output: []
	Explanation: We have "a","b" and "c" but no large group.
	Example 3:

	Input: "abcdddeeeeaabbbcd"
	Output: [[3,5],[6,9],[12,14]]
	
	https://leetcode.com/problems/positions-of-large-groups/description/
	
	*/
	
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        
        if (S.size() < 3) {
            return res;
        }
        
        int s = S.at(0);
        int count = 1;
        
        for (int i = 1; i < S.size(); i++) {
            if (s == S.at(i)) {
                count++;
            }
            else {
                
                if (count >= 3) {
                    res.push_back({i - count, i - 1});
                }
                
                s = S.at(i);
                count = 1;
            }
        }
        
        if (count >= 3) {
            res.push_back({S.size() - count, S.size() - 1});
        }
        
        return res;
    }
};