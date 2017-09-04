#include <iostream>
#include <numeric>

using namespace std;

int findMissingNum(int a[], int n) {
  int sum = (n+1)*(n+2) / 2;
  int arrSum = accumulate(a, a+n, 0);

  return (sum - arrSum);
}

int main(int argc, const char** argv) {
  int a[] = {1, 2, 3, 4, 6};
  int n   = sizeof(a) / sizeof(int);
  cout << findMissingNum(a, n) << endl;

  return 0;
}
