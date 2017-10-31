/* 
 * Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
 * Example 1:
 * Input: "aba"
 * Output: True
 * Example 2:
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * Note:
 * The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 */ 
#include <iostream>
#include <string>
using namespace std;

bool isValid(const string& s, int start, int end, int del) {
  if (start >= end) {
    return true;
  }
    
  //cout << s.at(start) << " " << s.at(end) << endl;
    
  if (s[start] == s[end]) {
    return isValid(s, start + 1, end - 1, del);
  }
  else {
    if (del > 0) {
      return isValid(s, start + 1, end, --del) || isValid(s, start, end - 1, --del);
    }
  }
  return false;
} 

bool validPalindrome(string s) {
  if (s.length() == 0) {
    return false;
  }
    
  return isValid(s, 0, s.length() - 1, 1);
}

int main(int argc, const char** argv) {
  string s = "abca";
  cout << validPalindrome(s) << endl;
  return 0;
}
