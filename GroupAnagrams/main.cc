/*
	Given an array of strings, group anagrams together.

	Example:

	Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
	Output:
	[
	  ["ate","eat","tea"],
	  ["nat","tan"],
	  ["bat"]
	]
	Note:

	All inputs will be in lowercase.
	The order of your output does not matter.
	
	https://leetcode.com/problems/group-anagrams/description/
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        
        map<string, vector<string>> hash;
        
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            hash[s].emplace_back(strs[i]);
        }
         
        for (auto i: hash) {
            result.push_back(i.second);
        }

        return result;
    }
};