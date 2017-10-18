/*
 * An edit between two strings is one of the following changes.
 * Add a character
 * Delete a character
 * Change a character
 * Given two string s1 and s2, find if s1 can be converted to s2 with exactly one edit. 
 * Expected time complexity is O(m+n) where m and n are lengths of two strings.
 */
#include <iostream>
#include <vector>
using namespace std;

bool isEditDistanceOne(const string& s1, const string& s2) {
  int m = s1.length();
  int n = s2.length();

  // if length diff is greater than 1 return false;
  if (abs(m - n) > 1) {
    return false;
  }

  int i = 0;
  int j = 0;
  int count = 0;

  while ((i < m) && (j < n)) {
    // if char are same at i & j, then increment i & j
    if (s1[i] == s2[j]) {
      i++;
      j++;
    }      // if char are not same at i & j, then increment count
    else {
      count++; 
      // if one string is greater than other, increment index for that, 
      // else if length are same, then increment index for i & j
      if (m > n) {
        i++;
      }
      else if (n > m) {
        j++;
      }
      else {
        i++;
        j++;
      }
    }
  }

  // technically the below part of the code can be writtes as
  // if ((i < m) || (j < n)) { count++; } 
  // by the time we reach here we know max string difference can be
  // 1 in length.
  while (i++ < m) { count++; }
  while (j++ < n) { count++; } 

  return (count == 1);
}

int main(int argc, const char** argv) {
  string s1 = "geek";
  string s2 = "egeek";

  cout << "One edit distance : " << isEditDistanceOne(s1, s2) << endl;
  return 0;
}
