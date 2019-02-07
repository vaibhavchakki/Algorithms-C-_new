/*
 https://leetcode.com/problems/compare-version-numbers/submissions/
 */
 
 class Solution {
public:
    
    int compare(const vector<int>& v1, const vector<int>& v2) {
        int iter = min(v1.size(), v2.size());
        
        //for (auto& i: v1) { cout << i << " ";} cout << endl;
        //for (auto& i: v2) { cout << i << " ";} cout << endl;
        
        for (int i = 0; i < iter; i++) {
            if (v1[i] > v2[i]) {
                return 1;
            }
            else if (v1[i] < v2[i]) {
                return -1;
            }
        }
        
        if (v1.size() > v2.size()) {
            for (int i = v2.size(); i < v1.size(); i++) {
                if (v1[i] != 0) {
                    //cout << i << endl;
                    return 1;
                }
            }
        }
        else if (v2.size() > v1.size()) {
            for (int i = v1.size(); i < v2.size(); i++) {
                if (v2[i] != 0) {
                    return -1;
                }
            }
        }
        
        return 0;
    }
    
    vector<int> parse(const string& v) {
        vector<int> res;
        string s = v;
        
        while (s.find('.') != string::npos) {
            string t = s.substr(0, s.find('.'));
            //cout << t << endl;
            res.push_back(atoi(t.c_str()));
            s = s.substr(s.find('.') + 1);
        }
        
        res.push_back(atoi(s.c_str()));
        return res;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> v1 = parse(version1);
        vector<int> v2 = parse(version2);
        
        return compare(v1, v2);
    }
};
