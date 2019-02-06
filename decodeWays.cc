/*
https://leetcode.com/problems/decode-ways/
 */
 
 class Solution {
public:
    
    void helper(string& s, int start, int& count) {
        
        if (start >= s.size()) {
            count++;
        }
        
        for (int i = start;i < s.size(); i++) {
            
            helper(s, i + 1, count);
            if (i < (s.size() - 1)) {
                string t = s.substr(i, 2);
                int num;
                stringstream ss(t);
                ss >> num;
                helper(s, i + 2, count);
            }
        }
    }
    
    int numDecodings(string s) {
        
        if (s.size() < 1) {
            return 0;
        }
        
        int count = 0;
        
        helper(s, 0, count);
        
        return count;
    }
};
