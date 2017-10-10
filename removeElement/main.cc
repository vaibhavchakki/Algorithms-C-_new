/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * Example:
 * Given input array nums = [3,2,2,3], val = 3
 * Your function should return length = 2, with the first two elements of nums being 2.
 */
#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
  int count = 0; 
  int len   = nums.size();  
  for (int i = 0; i < len; i++) {
     if (nums[i] == val) {
        count++; 
     }
     else {
        nums[i - count] = nums[i]; 
     } 
  }
  return len - count;  
}

int removeElement_2(vector<int>& nums, int val) {
  int len = nums.size();
        
  for (int i = 0; i < len; i++) {
    if (nums[i] == val) {
      nums.erase(nums.begin() + i);
      len--;
      i--;
    }
  }
  return len;
}

int main(int argc, const char** argv) {
  int n[] = {3, 2, 2, 3};
  vector<int> nums(n, n+4);
  int val = 3;

  cout << "New length: " << removeElement(nums, val) << endl;

  return 0;
}
