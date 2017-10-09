/* 
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(const vector<int>& nums, int target) {
    vector<int> result;
    map<int, int> targetNum;
    
    for (int i = 0; i < nums.size(); i++) {
        targetNum[nums[i]] = i;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        int findNum = target - nums[i];
        map<int, int>::iterator it = targetNum.find(findNum);
        
        if ((it != targetNum.end()) && (it->second != i)) {
            result.push_back(i);
            result.push_back(it->second);
            return result;
        }
        
        
    }
    
    return result;
}


int main(int argc, const char** argv) {
  int nums[] = {2, 7, 11, 15};
  int target = 9;
  vector<int> n(nums, nums+4);

  vector<int> result = twoSum(n, target);
  cout << "Result: " << result[0] << ", " << result[1] << endl;

  return 0;
}
