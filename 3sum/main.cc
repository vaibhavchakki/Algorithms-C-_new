/*
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note: The solution set must not contain duplicate triplets.
* 
* For example, given array S = [-1, 0, 1, 2, -1, -4],
* 
* A solution set is:
* [
*[-1, 0, 1],
*[-1, -1, 2]
* ]
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector <int> > res;
  
  if (nums.size() < 3) {
      return res;
  }
  
  map<string, int> hash;
  sort(nums.begin(), nums.end());
  
  for (int i = 0; i < nums.size() - 2; i++) {
    int p = i + 1;
    int q = nums.size() - 1;
      
    while (p < q) {
      int sum = nums[i] + nums[p] + nums[q];
      //cout << nums[i] << " " << nums[p] << " " << nums[q] << endl;
      if (sum == 0) {
        stringstream ss;
        ss << nums[i] << nums[p] << nums[q];
              
        if (hash.find(ss.str()) == hash.end()) {
          res.push_back({nums[i], nums[p], nums[q]});
          hash[ss.str()] = 1;
        }
        p++;
        q--;
      }
      else if (sum > 0) {
        q--;
      }
      else {
        p++;
      }
    }
  }
  return res;
}
