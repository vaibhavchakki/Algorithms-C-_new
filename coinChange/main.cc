/*
 * Given a value N, if we want to make change for N cents, and we have infinite supply 
 * of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? 
 * The order of coins doesn’t matter.
 * 
 * For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},
 * {2,2},{1,3}. So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five 
 * solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
 *
 * http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/
 */
#include <iostream>
using namespace std;

/*
 *  Ex: S[3]: [1, 2, 3] --> coins
 *         N: 4
 * 
 *   0  1  2  3  4
 *  ----------------
 *  |1 |1 |1 |1 |1 |  --> coin: 1
 *  ----------------
 *  |1 |  |2 |2 |3 |  --> coin: 2
 *  ----------------
 *  |1 |  |  |3 |4 |  --> coin: 3
 *  ----------------
 * return value: 4
 */
int coinChange(int S[], int numCoins, int N) {
  int tbl[N + 1];

  memset(tbl, 0, sizeof(tbl));
  
  tbl[0] = 1;

  for (int i = 0; i < numCoins; i++) { // iterate thru the number of coins
    for (int j = S[i]; j <= N; j++) { // Now look at the each value
      tbl[j] = tbl[j] + tbl[j - S[i]];
    }
  }
  return tbl[N];
}


/*
 * solution 2
 */
int coinChange_Soln2(int S[], int numCoins, int N) {
  int tbl[N+1][numCoins];
  
  memset(tbl, 0, sizeof(tbl));

  for (int i = 0; i < numCoins; i++) {
    tbl[0][i] = 1;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < numCoins; j++) {
      int x = (i - S[j] >= 0) ? tbl[i - S[j]][j] : 0;
      int y = (j > 0) ? tbl[i][j - 1] : 0;

      tbl[i][j] = x + y;   
    }
  }

  return tbl[N][numCoins - 1];
}


// main function
int main(int argc, const char** argv) {
  int S[] = {1, 2, 3};
  int m = sizeof(S)/sizeof(S[0]);
  int N = 4;
  cout << "Number of combinations: " << coinChange(S, m , N) << endl;
  cout << "Number of combinations: " << coinChange_Soln2(S, m , N) << endl;

  return 0;
}
