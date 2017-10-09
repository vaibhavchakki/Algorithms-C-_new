/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a 
 * contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 */
#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int s, const vector<int>& nums) {
  // Use sliding window appraoch
  
  // set the min length to max value
  int minlen = numeric_limits<int>::max();

  // set the start of sliding window
  int start = 0;

  // intialize the sum to 0
  int sum = 0;

  // for loop to collect sum 
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];

    // sliding window approach, if sum excceds s, then we need
    // to move the start window to the right and reduce the sum
    // also
    //  start ---- i
    while (sum >= s) {
      minlen = min(minlen, i - start + 1);
      // since we move the start index right now, we need to remove the value from 
      // sum and increase its index
      sum -= nums[start];
      start++; 
    }
  }
  
  // return the min len, return 0, if not found value
  return (minlen == numeric_limits<int>::max()) ? 0 : minlen;
}

int main(int argc, const char** argv) {
  int n[] = {2, 3, 1, 2, 4, 3};
  vector<int> nums(n, n + 6);
  int s = 7; // target

  cout << "Result = " << minSubArrayLen(s, nums) << endl; 
  return 0;
}
