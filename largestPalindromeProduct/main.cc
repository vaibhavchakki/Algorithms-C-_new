/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <iostream>
#include <sstream>

using namespace std;

bool isPalindrome(unsigned long num) {
  stringstream ss;
  ss << num;
  int end = ss.str().length() - 1;
  int begin = 0;
 
  while (begin < end) {
    if (ss.str().at(begin) == ss.str().at(end)) {
      begin++;
      end--;
    }
    else {
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  int n = 999; 
  int maxNum = 1;

  for (int i = n; i > 1; i--) {
    for (int j = n; j > 1; j--) {
      if (isPalindrome(i * j)) {
        maxNum = (i * j) > maxNum ? i * j: maxNum;
      }
    }
  }

  cout << maxNum << endl;

  return 0;
}
