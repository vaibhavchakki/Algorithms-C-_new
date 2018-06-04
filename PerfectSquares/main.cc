/*
	Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

	Example 1:

	Input: n = 12
	Output: 3 
	Explanation: 12 = 4 + 4 + 4.
	Example 2:

	Input: n = 13
	Output: 2
	Explanation: 13 = 4 + 9.
	
	https://leetcode.com/problems/perfect-squares/description/
	
	*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i * i <= n; i++) {
            dp[i * i] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <=i; j++) {
                dp[i] = min(dp[i], dp[j*j] + dp[i - (j * j)]);
            }
        }
     
        return dp[n];
    }
};