/* 
 * We have two special characters. The first character can be represented by one bit 0. 
 * The second character can be represented by two bits (10 or 11).
 * 
 * Now given a string represented by several bits. Return whether the last character must be a one-bit 
 * character or not. The given string will always end with a zero.
 * 
 * Example 1:
 * Input: 
 * bits = [1, 0, 0]
 * Output: True
 * Explanation: 
 * The only way to decode it is two-bit character and one-bit character. So the last character is one-bit character.
 * Example 2:
 * Input: 
 * bits = [1, 1, 1, 0]
 * Output: False
 * Explanation: 
 * The only way to decode it is two-bit character and two-bit character. So the last character is NOT one-bit character.
 * Note:
 * 
 * 1 <= len(bits) <= 1000.
 * bits[i] is always 0 or 1.
 */

#include <iostream>
#include <vector>
using namespace std;

bool helper(const vector<int>& bits, int index) {
  int len = bits.size();
    
  if (index < len) {
    if (index == len - 1) {
      return (bits[index] == 0);
    }
    else {
      if (bits[index] == 0) {
        return helper(bits, index + 1);
      }
        else if (bits[index] == 1) {
          return helper(bits, index + 2);
        }
      }
  }
  return false;
}

bool isOneBitCharacter(vector<int>& bits) {
  return helper(bits, 0);
}

bool isOneBitCharacter_solution2(vector<int>& bits) {
  int i = 0;
  int len = bits.size();
  while (i < len - 1) {
    if (bits[i] == 0) i++;
    else i += 2;
  }

  return i == (len - 1);
}

int main(int argc, const char** argv) {
  return 0;
}
