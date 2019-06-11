/* https://www.interviewbit.com/problems/min-jumps-array/ 
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.
*/

int Solution::jump(vector<int> &A) {
    vector<int> tbl(A.size(), 0);
    
    for (int i = 0; i < A.size(); i++) {
        int jump = A[i];
        for (int j = 1; j <= jump; j++) {
            int index = i + j;
            if (index < A.size()) {
                tbl[index] = (tbl[index] > 0) ? min(tbl[index], tbl[i] + 1) : tbl[i] + 1;
            }
        }
    }
    
    /*for (int i = 0; i < A.size(); i++) {
        cout << tbl[i] << " ";
    }
    cout << endl;*/
    
    return tbl[A.size() - 1] == 0 ? -1 : tbl[A.size() - 1];
}
