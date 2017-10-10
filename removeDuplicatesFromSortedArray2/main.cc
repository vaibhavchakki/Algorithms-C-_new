/*
 * Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array nums = [1,1,1,2,2,3],
 * Your function should return length = 5, with the first five elements of nums being 
 * 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
  int c = 0;
  int len = nums.size();
  for (int i = 1; i < len; i++) {
    if (nums[i] == nums[i-1]) {
      c += 1;
      if (c >= 2) {
        nums.erase(nums.begin() + i);
        len--;
        i--;
      }
    }
    else {
      c = 0;
    }
  }
  return len;
}

int removeDuplicates_2(vector<int>& nums) {
  int n = nums.size(), count = 0;
  for (int i = 2; i < n; i++) {
    if (nums[i] == nums[i - 2 - count]) count++;
    else nums[i - count] = nums[i];
  }
  return n - count;
}

int main(int argc, const char** argv) {
  int n[] = {1, 1, 2, 2, 2, 3};
  vector<int> nums(n, n+6);

  cout << "New length = " << removeDuplicates_2(nums) << endl;
  return 0;
}
