/*
 * Following are common definition of Binomial Coefficients.
 * 1) A binomial coefficient C(n, k) can be defined as the coefficient of X^k in the 
 *    expansion of (1 + X)^n.
 * 2) A binomial coefficient C(n, k) also gives the number of ways, disregarding order, 
 *    that k objects can be chosen from among n objects; more formally, the number of 
 *    k-element subsets (or k-combinations) of an n-element set.
 *
 * The Problem
 * Write a function that takes two parameters n and k and returns the value of Binomial 
 * Coefficient C(n, k). For example, your function should return 6 for n = 4 and k = 2, 
 * and it should return 10 for n = 5 and k = 2.
 * http://www.geeksforgeeks.org/dynamic-programming-set-9-binomial-coefficient/
 */

#include <iostream>
using namespace std;

int binomialCoeff(int n, int k) {
  int tbl[n+1][k+1];

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= min(i, k); j++) {
      if ((j == 0) || (j == i)) {
        tbl[i][j] = 1;
      }
      else { 
        tbl[i][j] = tbl[i-1][j-1] + tbl[i-1][j];
      }
    }
  }
 
  return tbl[n][k]; 
}

int main(int argc, const char** argv) {
  int n = 5, k = 2;
  
  cout << "Value of C(" << n << ", " << k << ") is: " 
       << binomialCoeff(n, k) << endl;

  return 0;
}
