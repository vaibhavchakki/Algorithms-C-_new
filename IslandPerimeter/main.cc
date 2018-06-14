/*
	You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

	Example:

	[[0,1,0,0],
	 [1,1,1,0],
	 [0,1,0,0],
	 [1,1,0,0]]

	Answer: 16
	Explanation: The perimeter is the 16 yellow stripes in the image below:
	
	https://leetcode.com/problems/island-perimeter/description/
*/

class Solution {
public:
    int get_cell_perimeter(const vector<vector<int>>& grid, int x, int y, int rows, int cols) {
        static int x_i[] = {-1, 1, 0, 0};
        static int y_i[] = {0, 0, -1, 1};
        
        int cell_perimeter = 4;
        
        for (int k = 0; k < 4; k++) {
            int new_x = x + x_i[k];
            int new_y = y + y_i[k];
            
            if ((new_x >= 0) && (new_x < rows) && (new_y >= 0) && (new_y < cols) && (grid[new_x][new_y] == 1)) {
                cell_perimeter--;
            }
        }
        
        return cell_perimeter;
    }
    
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        
        if (rows < 1) {
            return 0;
        }
        
        int cols = grid[0].size();
        int perimeter = 0;
        
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (grid[x][y] == 1) {
                    perimeter += get_cell_perimeter(grid, x, y, rows, cols);
                }
            }
        }
        
        return perimeter;
    }
};
