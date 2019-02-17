/* https://leetcode.com/problems/palindromic-substrings */

class Solution {
public:
    
    int expand(int i, int j, const string& s) {
        int res = 0;
        
        while ((i >= 0) && (j < s.size())) {
            if (s[i] != s[j]) { break; }
            i--; j++;
            res++;
        }
        
        return res;
    }
    
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res++;
            
            if ((i + 1) < s.size()) {
                res += expand(i, i + 1, s);
            }
            res += expand(i - 1, i + 1, s);
        }
        return res;
    }
};
