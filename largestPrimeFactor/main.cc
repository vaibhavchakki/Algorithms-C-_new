/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
 */

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
  
  for (int i = 2; i <= sqrt(n); i++) {
    if (!(n % i)) {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv)
{
  unsigned maxFactor = 1;
  unsigned long num = 600851475143;

  for (int i = 2; i <= sqrt(num); i++) {
    bool isprime = isPrime(i);
 
    if (isprime && !(num % i)) {
      maxFactor = i > maxFactor ? i : maxFactor;
    }
  }

  cout << maxFactor << endl;

  return 0;
}
