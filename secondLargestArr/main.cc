#include <iostream>
#include <climits>
using namespace std;

int secondLargest(int *arr, int N) {
  int max_1 = INT_MIN;
  int max_2 = INT_MIN;

  for (int i = 0; i < N; i++) {
    if (arr[i] > max_1) {
      max_2 = max_1;
      max_1 = arr[i];
    }
  }
  return max_2;
}

int main(int argc, char** argv) {
  int arr[]= {-1, 6, 7, 0, 10, 12};
  int N = sizeof(arr) / sizeof(int);

  cout << "2nd largest in array is: " << secondLargest(arr, N) << endl;
  return 0;
}
