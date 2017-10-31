/* 
 * Given two arrays, write a function to compute their intersection.
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * Note:
 * Each element in the result must be unique.
 * The result can be in any order.
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
  vector<int> result;
  set<int> Set1;
  for (int &n: nums1) {
    Set1.emplace(n);
  }
    
  set<int> Set2;
  for (int& n: nums2) {
    if ((Set1.find(n) != Set1.end()) && 
        (Set2.find(n) == Set2.end())) {
      result.push_back(n);
      Set2.emplace(n);
    }
  }
    
  return result;
}

int main(int argc, const char** argv) {
  return 0;
}
