/*
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * https://leetcode.com/problems/multiply-strings/description/
 */
 class Solution {
public:
    vector<int> str_to_list(const string& s) {
        vector<int> res;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            res.emplace_back(s[i] - '0');
        }
        return res;
    }
    
    
    string list_to_str(const vector<int>& v) {
        string res = "";
        bool skip_zeros = true;
        for (int i = v.size() - 1; i >= 0; i--) {
            
            if (skip_zeros && (v.at(i) == 0)) {
                continue;
            }
            skip_zeros = false;
            res = res + static_cast<char>(v.at(i) + '0');
        }
        
        return (res.size() > 0) ? res : "0";
    }
    
    vector<int> multiply(const vector<int>& A, const vector<int>& B) {
        int c_size = A.size() + B.size();
        
        vector<int> C(c_size, 0);
        
        for (int i = 0; i < A.size() ; i++) {
            for (int j = 0; j < B.size(); j++) {
                C.at(i + j) += A.at(i) * B.at(j);
            }
        }
        int carry = 0;
        for (int i = 0; i < c_size; i++) {
            C.at(i) += carry;
            carry = C.at(i) / 10;
            C.at(i) = C.at(i) % 10;
        }
        
        return C;
    }
    
    string multiply(string num1, string num2) {
        
        vector <int> A = str_to_list(num1);
        vector <int> B = str_to_list(num2);
        
        vector <int> C = multiply(A, B);
        
        return list_to_str(C);
    }
};
 