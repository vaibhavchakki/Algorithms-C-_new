/* 
 * Given an array of integers that is already sorted in ascending order, find two numbers such that 
 * they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, 
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
 * are not zero-based.
 * 
 * You may assume that each input would have exactly one solution and you may not use the same element twice.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */
#include <iostream>
#include <vector>
using namespace std;

int find(const vector<int>& nums, int n, int s, int e) {
  if (s > e) {
    return -1;
  }
   
  int m = (s+e) / 2;
 
  if (nums[m] == n) {
    return m;
  }
  else if (nums[m] < n) {
    return find(nums, n, m + 1, e);
  }
  else {
    return find(nums, n, s, m - 1);
  }
}

vector<int> twoSumSorted(const vector<int>& nums, int target) {
  int size = nums.size();
  vector<int> result;
  
  for (int i = 0; i < size; i++) {
    int findNum = find(nums, (target - nums[i]), i + 1, size);

    if (findNum != -1) {
      result.push_back(i + 1);
      result.push_back(findNum + 1);
      break;
    }
  }
  return result;
}

int main(int argc, const char** argv) {
  int nums[] = {2, 7, 11, 15};
  int target = 9;
  vector<int> n(nums, nums+4);

  vector<int> result = twoSumSorted(n, target);
  cout << "Result: " << result[0] << ", " << result[1] << endl;

  return 0;
}
