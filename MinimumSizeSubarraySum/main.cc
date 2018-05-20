/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 * 
 * Example: 
 * 
 * Input: [2,3,1,2,4,3], s = 7
 * Output: 2
 * Explanation: the subarray [4,3] has the minimal length under the problem constraint.
 *
 * https://leetcode.com/problems/minimum-size-subarray-sum/description/
 */

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        /*
        if (nums.size() < 1) {
            return 0;
        }
        
        vector<int> dp(nums.size(), -1);
        
        dp[0] = (nums[0] >= s) ? 1 : 0;
        
        int minlen = (dp[0] ? dp[0] : INT_MAX);
        
        for (int i = 1; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += nums[j];
                if (sum >= s) {
                    dp[i] = (i - j) + 1;
                    minlen = min(dp[i], minlen);
                    break;
                }
            }
        }
        
        return (minlen == INT_MAX) ? 0 : minlen;*/
        
        // sliding window approach
        
        int len = nums.size();
        int i = 0;
        int minlen = INT_MAX;
        int sum = 0;
        int start = 0;
        
        while (i < len) {
            
            while ( (sum < s) && (i < len)) { sum += nums[i++]; }
            
            while (sum >= s) {
                minlen = min (i - start, minlen);
                sum -= nums[start++];
            }
        }
        
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};