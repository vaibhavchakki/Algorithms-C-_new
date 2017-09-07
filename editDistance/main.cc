/*
 * Given two strings str1 and str2 and below operations that can performed on str1. 
 * Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.
 * 
 * Insert
 * Remove
 * Replace
 * All of the above operations are of equal cost.
 * http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
 */
#include <iostream>
using namespace std;

int editDistance(const string& str1,
                 const string& str2) {
  int m = str1.length();
  int n = str2.length();

  int dp[m+1][n+1];

  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0) {
        dp[i][j] = j;
      }
      else if (j == 0) {
        dp[i][j] = i;
      }
      else if (str1.at(i - 1) == str2.at(j - 1)) {
        dp[i][j] = dp[i - 1][j - 1];
      }
      else {
        dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), 
                           dp[i-1][j-1]);
      }
    }
  }

  return dp[m][n];
}

int main(int argc, const char** argv) {
  string str1 = "sunday";
  string str2 = "saturday";
 
  cout << editDistance( str1 , str2 ) << endl;

  return 0;
}
