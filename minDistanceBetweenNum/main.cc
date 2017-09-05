/*
 * Find the minimum distance between two numbers. Given an unsorted array arr[] 
 * and two numbers x and y, find the minimum distance between x and y in arr[]. 
 * The array might also contain duplicates. You may assume that both x and y are 
 * different and present in arr[].
 *
 * Examples:
 * Input: arr[] = {1, 2}, x = 1, y = 2
 * Output: Minimum distance between 1 and 2 is 1.
 *
 * Input: arr[] = {3, 4, 5}, x = 3, y = 5
 * Output: Minimum distance between 3 and 5 is 2.
 *
 * Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
 * Output: Minimum distance between 3 and 6 is 4.
 *
 * Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
 * Output: Minimum distance between 3 and 2 is 1.
 */

#include <iostream>
using namespace std;

int minDistanceBetweenNum(int arr[], int n, int x, int y) {
  int i = 0;
  int start = -1;
  int minDist = INT_MAX;

  for (i = 0; i < n; i++) {
    if ( (arr[i] == x) || (arr[i] == y) ) {
      start = i;
      break;
    }
  }
  
  for ( ; i < n; i++) {
    if ( (arr[i] == x) || (arr[i] == y) ) {

      if ( (arr[i] != arr[start]) && (minDist > (i - start)) ) {
        minDist = (i - start);
      }
      start = i;
    }
  }

  return minDist;
}

int main(int argc, const char** argv) {
  int arr[] ={3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int x = 3;
  int y = 6;

  cout << "Min distance between " << x << " and " << y << " is: "
       << minDistanceBetweenNum(arr, n, x, y) << endl;
  return 0;
}
