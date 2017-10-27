/* 
 * Your are given an array of positive integers nums.
 * Count and print the number of (contiguous) subarrays where the product of all the elements in the 
 * subarray is less than k.
 * 
 * Example 1:
 * Input: nums = [10, 5, 2, 6], k = 100
 * Output: 8
 * Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], 
 *              [5, 2], [2, 6], [5, 2, 6]. Note that [10, 5, 2] is not included as the product of 
 *              100 is not strictly less than k.
 */
#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(const vector<int>& nums, int k) {
  int count = 0;
  long prod = 1;
  int left = 0; // left pointer of the window

  // Handle special conditions for the value of k
  if (k <= 1) {
    return 0;
  }
  
  // loop thru the nums array
  for (int i = 0; i < nums.size(); i++) {
    prod = prod * nums[i];
  
    // if this prod is greater than k, then find when the prod became greater than k
    // by incrementing the left index
    while ( (prod >= k) && (left <= i)) {
      prod = prod / nums[left];
      left++;
    }
   
    // count the number
    count += (i - left + 1);  
  }

  return count;
}

int main(int argc, const char** argv) {
  int n[] = {10, 5, 2, 6};
  int k = 100;
  vector<int> nums(n, n+4);

  cout << numSubarrayProductLessThanK(nums, k) << endl;
  return 0;
}
