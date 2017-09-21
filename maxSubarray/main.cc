/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 * 
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 * https://leetcode.com/problems/maximum-subarray/description/
 * http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 */
#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(const vector<int>& nums) {
  if (nums.size() < 1) {
    return INT_MIN;
  }

  // set the first element of maxNums to the nums
  vector<int> maxNums(nums.size());
  maxNums[0] = nums[0];
  int maxSum = nums[0];

  // look at the previous maxNums & sum it with the current nums value
  // if this value is greater than the current nums value, then put this 
  // in maxNums array, else just copy the nums value to maxNums array
  for (int i = 1; i < nums.size(); i++) {
    if ( (maxNums[i-1] + nums[i]) > nums[i] ) {
      maxNums[i] = maxNums[i-1] + nums[i];
    }
    else {
      maxNums[i] = nums[i];
    }
    // update the maxSum value every iteration
    maxSum = max(maxNums[i], maxSum);
  }  

  return maxSum;
}

int main() {
  int n[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  vector<int> nums(n, n + 9);

  cout << "Max Sub Array sum is: " << maxSubArray(nums) << endl;
  return 0;
}
