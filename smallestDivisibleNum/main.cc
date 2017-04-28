/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  int N = 20;
  unsigned int num = N - 1;
  bool done = false;

  while (1) {
    num++;
    for (int i = 2; i <= N; i++) {
      if (num % i) {
        break;
      }
      if (i == N) {
        done = true;
      }
    }
    if (done) {
      break;
    }
  }
 
  cout << num << endl;
  return 0;
}
