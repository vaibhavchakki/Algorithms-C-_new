/*
 * Write a function that list any 3 elements that sum to zero, from an array of integers.
 * Notes:
 * We need all unique solutions. (-5, -5, 10) is same as (10, -5, -5)
 * The same element can be used multiple times.
 * Example
 * Input: [-5, 1, 10, 2, 3] // array of integers
 * Output: [(-5, -5, 10), (-5, 2, 3)] // array of tuples
 */
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void tupleCombinationSum(vector<int>& nums, set< vector<int> >& tuples) {
  int len = nums.size();
  sort(nums.begin(), nums.end());

  for (int i = 0; i < len; i++) {
    int target_sum = 0 - nums[i];

    int start = i;
    int end   = len - 1;

    while (start <= end) {
      if ((nums[start] + nums[end]) == target_sum) {
        vector<int> ans(3);
        ans.push_back(nums[i]); ans.push_back(nums[start]); ans.push_back(nums[end]);
        sort(ans.begin(), ans.end());
        tuples.insert(ans);
        start++;
        end--;
      } 
      else if ((nums[start] + nums[end]) > target_sum) {
        end--;
      }
      else {
        start++;
      }
    }
  } 
}

int main() {
  set< vector<int> > tuples;
  int n[] = {-5, 1, 10, 2, 3};
  vector<int> nums(n, n+5);
  
  tupleCombinationSum(nums, tuples);

  for (auto i = tuples.begin(); i != tuples.end(); i++) {
    cout << "( ";
    for (auto j = (*i).begin(); j != (*i).end(); j++) {
      cout << *j << " ";
    }
    cout << " )" << endl;
  }

  return 0;
}
