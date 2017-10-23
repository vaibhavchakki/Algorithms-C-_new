/* 
 * Given a set of distinct integers, nums, return all possible subsets.
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * For example,
 * If nums = [1,2,3], a solution is:
 * 
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& n) {
  for (int i = 0; i < n.size(); i++) {
    cout << n[i] << " ";
  }
  cout << endl;
}

void helper(const vector<int>& nums, vector<int> subset, int startindex,
            vector< vector<int> >& result) {
  result.push_back(subset);
  for (int i = startindex; i < nums.size(); i++) {
    subset.push_back(nums[i]);
    helper(nums, subset, startindex + 1, result);
    subset.pop_back();
  }
}

vector< vector<int> > subsets(const vector<int>& nums) {
  vector< vector<int> > result;
  vector<int> subset;
  helper(nums, subset, 0, result);
  return result;
}

int main(int argc, const char** argv) {
  int n[] = {1, 2, 3};
  vector<int> nums(n, n + 3);
  
  vector< vector<int> > result = subsets(nums);
  
  for (int i = 0; i < result.size(); i++) {
    cout << "Set " << i << ": ";
    print(result[i]);
  }

  return 0;
}
