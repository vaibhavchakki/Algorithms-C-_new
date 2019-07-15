/*
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]
 */
 
 vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> res;
    
    if (A < 1) { return res; }
    res.push_back({1});
    
    
    for (int i = 1 ; i < A; i++) {
        vector<int> row;
        int n = 1;
        for (int j = 0; j <= i; j++) {
            row.push_back(n);
            n = n * (i - j) / (j + 1);
        }
        res.push_back(row);
    }
    
    
    return res;
}
