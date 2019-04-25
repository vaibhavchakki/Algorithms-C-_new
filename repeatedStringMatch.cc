class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int repeated = 1;
        if (A.length() > B.length()) {
            swap(A, B);
        }
        
        
        while (A.length() <= (2 * B.length())) {
            
            if (A.find(B) != string::npos) {
                return repeated;
            }
            
            A = A + A;
            repeated++;
        }
        
        return -1;
    }
};
