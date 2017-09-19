/*
 * Given an array of integers and an integer k, you need to find the total number of continuous 
 * subarrays whose sum equals to k.
 * 
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 */
#include <iostream>
#include <vector>

using namespace std;

int subArraySum(vector<int>& nums, int k) {
  int count = 0;
  int len = nums.size();
  int sum = 0;

  for (int start = 0; start < len; start++) {
    int sum = 0;
    
    for (int end = start; end < len; end++) {
      sum += nums[end];

      if (sum == k) {
        count++;
      }
      /*
       * cannot use this because there might be negative numbers, which can reduce the sum
       * of contigious arrays
      else if (sum > k) {
        break;
      }*/
    }
  }
  
  return count;
}


int main(int argc, const char** argv) {
  int n[] = {1, 1, 1};
  int k = 2;

  vector<int> nums(n, n+3);

  cout << "Num subarrays: " << subArraySum(nums, k) << endl;
  return 0;
}
