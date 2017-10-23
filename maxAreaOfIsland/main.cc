/*
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
 * connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are 
 * surrounded by water.
 * Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
 * 
 * Example 1:
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * [0,0,0,0,0,0,0,1,1,1,0,0,0],
 * [0,1,1,0,1,0,0,0,0,0,0,0,0],
 * [0,1,0,0,1,1,0,0,1,0,1,0,0],
 * [0,1,0,0,1,1,0,0,1,1,1,0,0],
 * [0,0,0,0,0,0,0,0,0,0,1,0,0],
 * [0,0,0,0,0,0,0,1,1,1,0,0,0],
 * [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
 * Example 2:
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 */

#include <iostream>
#include <vector>
using namespace std;

int getArea(const vector<vector<int>>& grid, int i, int j, int rows, int cols, int& area, vector<vector<int>>& visited) {
  if ( (i < rows) && (j < cols)  && (grid[i][j] == 1) && !visited[i][j]) {
    area++;
    visited[i][j] = 1;
    if ((i + 1)  < rows) {
      getArea(grid, i + 1, j, rows, cols, area, visited);
    }
              
    if ((i - 1)  >= 0) {
      getArea(grid, i - 1, j, rows, cols, area, visited);
    }
        
    if ((j + 1) < cols) {
      getArea(grid, i, j + 1, rows, cols, area, visited);
    }
        
    if ((j - 1) >= 0) {
      getArea(grid, i, j - 1, rows, cols, area, visited);
    }
  }
  return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
  int maxArea = 0;
  int rows = grid.size();
    
  if (rows < 1) {
    return maxArea;
  }
    
  int cols = grid[0].size();
    
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (grid[i][j] == 1) {
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int area = 0;
                
        getArea(grid, i, j, rows, cols, area, visited);
        maxArea = max(area, maxArea);
      }
    }
  }
    
  return maxArea;
}


int main(int argc, const char** argv) {
  return 0;
}

/*
 Text book solution

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == 1)max_area = max(max_area, AreaOfIsland(grid, i, j));
        return max_area;
    }
    
    int AreaOfIsland(vector<vector<int>>& grid, int i, int j){
        if( i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
            grid[i][j] = 0;
            return 1 + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
        }
        return 0;
    }
*/
