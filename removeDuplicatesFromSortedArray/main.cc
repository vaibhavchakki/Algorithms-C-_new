/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once 
 * and return the new length. Do not allocate extra space for another array, you must do this in 
 * place with constant memory.
 * For example,
 * Given input array nums = [1,1,2],
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 
 * respectively. It doesn't matter what you leave beyond the new length.
 */
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
  int len = nums.size();
    
  for (int i = 1; i < len; i++) {
    if (nums[i - 1] == nums[i]) {
      nums.erase(nums.begin() + i);
      len--;
      i--;
      }
  }
  return len;
}

int removeDuplicates_2(vector<int>& nums) {
  int i = 0;
  for (int n : nums) {
    if (i == 0 || n > nums[i-1]) {
      nums[i++] = n;
    }
  }
  return i;
}

int main(int argc, const char** argv) {
  int n[] = {1, 1, 2, 2, 2, 3};
  vector<int> nums(n, n+6);

  cout << "New length = " << removeDuplicates_2(nums) << endl;
  return 0;
}
