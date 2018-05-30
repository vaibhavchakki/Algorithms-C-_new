/*
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

	Note:

	The same word in the dictionary may be reused multiple times in the segmentation.
	You may assume the dictionary does not contain duplicate words.
	Example 1:

	Input: s = "leetcode", wordDict = ["leet", "code"]
	Output: true
	Explanation: Return true because "leetcode" can be segmented as "leet code".
	Example 2:

	Input: s = "applepenapple", wordDict = ["apple", "pen"]
	Output: true
	Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
				 Note that you are allowed to reuse a dictionary word.
	Example 3:

	Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
	Output: false

	https://leetcode.com/problems/word-break/description/
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.length() + 1);
        dp[0] = 1;
        
        set<string> dict;
        for (auto& s: wordDict) { dict.insert(s); }
        
        for (int i = 1; i <= s.length(); i++) {
            dp[i] = 0;
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, (i - j)))) {
                    dp[i] = 1;
                } 
            }
        }
        
        return dp[s.length()];
    }
};