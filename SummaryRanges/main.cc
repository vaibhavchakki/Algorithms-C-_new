/*
 * Given a sorted integer array without duplicates, return the summary of its ranges.
 * Example 1:
 * Input: [0,1,2,4,5,7]
 * Output: ["0->2","4->5","7"]
 * Example 2:
 * Input: [0,2,3,4,6,8,9]
 * Output: ["0","2->4","6","8->9"]
 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void updateResult(int first, int prev, vector<string>& result) {
  if (first == prev) {
    stringstream ss;
    ss << first;
    result.push_back(ss.str());
  }
  else {
    stringstream ss;
    ss << first << "->" << prev;
    result.push_back(ss.str());
  }
}

vector<string> summaryRanges(vector<int>& nums) {
  vector<string> result;
    
  if (nums.size() < 1) {
    return result;
  } 
 
  // set the first number and prev number vars to the
  // first element of the array
  int first = nums[0];
  int prev = nums[0];
    
  // iterate thru the 2nd element to end of array
  for (int i = 1; i < nums.size(); i++) {
    // if the curr num is not equal to prev + 1, then generate string and push the 
    // result. If the prev num is same as first then, we just generate ""
    // else, we generate "first->prev" and then we update the first to curr num
    if (nums[i] != prev + 1) {
      updateResult(first, prev, result);
      first = nums[i];
    }
    // update the prev number everytime
    prev = nums[i];
  }

  // update for the last result, outside the for loop
  updateResult(first, prev, result);
    
  return result;
}

int main(int argc, const char** argv) {
  int nums[] = {0,2,3,4,6,8,9};
  vector<int> n(nums, nums+7);
  
  cout << "Summary Ranges is: [ ";
 
  for (auto s : summaryRanges(n)) {
    cout << s << " ";
  } 
  cout << "]" << endl;
  return 0;
}
