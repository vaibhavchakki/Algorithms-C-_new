/*
 * Given a sequence, find the length of the longest palindromic subsequence in it. For example, 
 * if the given sequence is “BBABCBCAB”, then the output should be 7 as “BABCBAB” is the longest 
 * palindromic subseuqnce in it. “BBBBB” and “BBCBB” are also palindromic subsequences of the given 
 * sequence, but not the longest ones.
 * 
 * The naive solution for this problem is to generate all subsequences of the given sequence and 
 * find the longest palindromic subsequence. This solution is exponential in term of time complexity. 
 * Let us see how this problem possesses both important properties of a Dynamic Programming (DP) 
 * Problem and can efficiently solved using Dynamic Programming.
 * http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
 */
#include <iostream>
#include <vector>
using namespace std;

/*
 * Explanation:
 * String: BABCBAB
 *      B    A   B   C   B   A   B
 *      0    1   2   3   4   5   6
 *      ---------------------------
 * B  0| 1 | 1 | 3 | 3 | 3 | 5 | 7 |
 *      ---------------------------
 * A  1|   | 1 | 1 | 1 | 3 | 5 | 5 |
 *      ---------------------------
 * B  2|   |   | 1 | 1 | 3 | 3 | 3 |
 *      ---------------------------
 * C  3|   |   |   | 1 | 1 | 1 | 3 |
 *      ---------------------------
 * B  4|   |   |   |   | 1 | 1 | 3 |
 *      ---------------------------
 * A  5|   |   |   |   |   | 1 | 1 |
 *      ---------------------------
 * B  6|   |   |   |   |   |   | 1 |
 *      ---------------------------
 */
int longestPalindromicSubstring(const string& s) {
  int len = s.length();
  int dp[len][len];

  memset(dp, 0, sizeof(dp));

  // each character is a palindrome so mark them as 
  // length of 1
  for (int i = 0; i < len; i++) {
    dp[i][i] = 1;
  }

  // now look at length of 2,3.. len -1 if they palindrome
  for (int k = 2; k <= len; k++) { // this is iterating thru the different lengths like 2, 3, 4, ...
    for (int i = 0; i < len - k + 1; i++) { // this is starting from index 0
      int j = i + k - 1;                    // this points to character at distance (i + k)
      if (s.at(i) == s.at(j)) {             // if the characters are same
        if (k == 2) {                       // special case for length = 2, i.e. k = 2
          dp[i][j] = 2;
        }
        else {
          dp[i][j] = dp[i+1][j-1] + 2;
        }
      }
      else {
        dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
      }
    }
  }

  cout << endl;
  for (int i = 0 ; i < len; i++) {
    for (int j = 0; j < len; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }

  return dp[0][len - 1];
}


int main() {
  string s = "BABCBAB";

  cout << "Length of longest palindrome " << s << " is: " << longestPalindromicSubstring(s) << endl;
  return 0;
}
