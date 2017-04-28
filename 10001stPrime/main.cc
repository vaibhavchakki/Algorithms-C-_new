/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
 */
#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int N) {
  for (int i = 2; i <= sqrt(N); i++) {
    if ((N % i) == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  int N = 2;
  int count = 0;
  
  while (1) {
    bool is_prime = isPrime(N);

    if (is_prime) {
      count++;
      if (count == 10001) {
        break;
      }
    }
    N++;
  }
  cout << N << endl;

  return 0;
}

