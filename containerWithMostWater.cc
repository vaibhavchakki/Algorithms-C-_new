/*
https://leetcode.com/problems/container-with-most-water/
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        if (height.size() < 1) {
            return 0;
        }
        
        int i = 0;
        int j = height.size() - 1;
        int maxarea = 0;
        
        while (i < j) {
            int h = min(height[i], height[j]);
            maxarea = max(maxarea, (h * (j - i)));
            
            while ((height[i] <= h) && (i < j)) i++;
            while ((height[j] <= h) && (i < j)) j--;
        }
        
        return maxarea;
    }
};
