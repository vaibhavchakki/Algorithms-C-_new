/*
 * Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function
 * that returns cost of minimum cost path to reach (m, n) from (0, 0). Each cell of 
 * the matrix represents a cost to traverse through that cell. Total cost of a path
 * to reach (m, n) is sum of all the costs on that path (including both source and 
 * destination). You can only traverse down, right and diagonally lower cells from 
 * a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1) and (i+1, j+1) 
 * can be traversed. You may assume that all costs are positive integers.
 *
 * http://www.geeksforgeeks.org/dynamic-programming-set-6-min-cost-path/
 */
#include <iostream>
using namespace std;

int min3(int x, int y, int z) {
  return min (min(x, y), z);
}

int minCost(int arr[3][3], int r, int c) {
  int costArr[r][c];

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if ((i == 0) && (j == 0)) {
        costArr[i][j] = arr[i][j];
      }
      else if (i == 0) {
        costArr[i][j] = costArr[i][j-1] + arr[i][j];
      }
      else if (j == 0) {
        costArr[i][j] = costArr[i - 1][j] + arr[i][j];
      }
      else {
        costArr[i][j] = min3(costArr[i-1][j-1], 
                             costArr[i-1][j],
                             costArr[i][j-1]) + arr[i][j];
      }
    }
  }

  return costArr[r-1][c-1];
}

int main(int argc, const char** argv)
{
   int cost[3][3] = { {1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3} };
   cout << "Cost: " << minCost(cost, 3, 3) << endl;
   return 0;
}
