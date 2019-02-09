/* https://leetcode.com/problems/wiggle-sort-ii/ */

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto temp = nums;
        sort(temp.begin(), temp.end());
        
        int idx = 0;
        int mid = temp.size() / 2 + (temp.size() % 2);
        for (int i = mid - 1; i >= 0; i--) {
            nums[idx] = temp[i];
            idx += 2;
        }
        
        idx = 1;
        for (int i = temp.size() - 1;  i >= mid; i--) {
            nums[idx] = temp[i];
            idx += 2;
        }
    }
};
