/*
 * The Longest Increasing Subsequence (LIS) problem is to find the length 
 * of the longest subsequence of a given sequence such that all elements 
 * of the subsequence are sorted in increasing order. For example, the 
 * length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is 
 * {10, 22, 33, 50, 60, 80}.
 */

#include <iostream>
using namespace std;

int LIS(int a[], int n) {
  int maxLen = 1;
  int len[n];

  for (int i = 0; i < n; i++) {
    len[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if ( (a[i] > a[j])  && (len[i] < (len[j] + 1)) ) {
        len[i] = len[j] + 1;
        maxLen = max(maxLen, len[i]); 
      }
    }
  }
  
  return maxLen; 
}

int main(int argc, const char** argv) {
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << "Length is: " << LIS(arr, n) << endl;

  return 0;
}
