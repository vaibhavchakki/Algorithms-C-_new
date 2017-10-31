/*
 * Given a list of words and two words word1 and word2, return the shortest distance
 * between these two words in the list.
 * For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * Given word1 = “coding”, word2 = “practice”, return 3. Given word1 = "makes",
 * word2 = "coding", return 1.
 */
#include <iostream>
#include <vector>
using namespace std;

int shortestWordDistance(vector<string>& words, string& w1, string& w2) {
  int i1 = -1;
  int i2 = -1;
  int minDistance = numeric_limits<int>::max();

  for (int i = 0; i < words.size(); i++) {
    if (words[i].compare(w1) != 0) {
      i1 = i;
      minDistance = (i2 != -1) ? min(minDistance, abs(i2 - i1)) : minDistance;
    }
    else if (words[i].compare(w2) != 0) {
      i2 = i;
      minDistance = (i1 != -1) ? min(minDistance, abs(i2 - i1)) : minDistance;
    }
  }

  return minDistance;
}

int main(int argc, const char** argv) {
  
  return 0;
}
