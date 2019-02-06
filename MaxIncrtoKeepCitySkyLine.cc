//Max Increase to Keep City Skyline
//https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector <int> rowMax;
        vector <int> colMax;
        
        int rows = grid.size();
        
        if (rows < 1) {
            return 0;
        }
        
        int cols = grid[0].size();
        
        for (int i = 0; i < rows; i++) {
            int maxVal = 0;
            
            for (int j = 0; j < cols; j++) {
                maxVal = max(maxVal, grid[i][j]);
            }
            
            rowMax.push_back(maxVal);
        }
        
        
        for (int i = 0; i < cols; i++) {
            int maxVal = 0;
            
            for (int j = 0; j < rows; j++) {
                maxVal = max(maxVal, grid[j][i]);
            }
            
            colMax.push_back(maxVal);
        }
        int maxIncrease = 0;
        for (int i = 0; i < rows; i++) {
            int row = rowMax[i];
            for (int j = 0; j < cols; j++) {
                int col = colMax[j];
                
                maxIncrease += abs (min(row, col) - grid[i][j]);
            }
        }
        
        return maxIncrease;
    }
};
