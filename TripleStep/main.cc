/*
 * 8.1 Triple Step: A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3
 * steps at a time. Implement a method to count how many possible ways the child can run up the stairs.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
int numWays_solution1(int n) {
  if (n < 1) {
    return 0;
  }

  vector<int> ways(n+1, 0);
  ways[0] = 1;

  int numHops = 3;
  for (int i = 1; i <= numHops; i++) {
    for (int j = i; j <= n; j++) {
      ways[j] += ways[j - i];
    }
  }
 
  return ways[n];
}
*/

vector<int> ways;

void init(int n) {
  for (int i = 0; i <= n; i++) {
    ways.push_back(-1);
  }
}

int numWays_solution2(int n) {
  if (n < 0) {
    return 0;
  }
  if (n == 0) {
    return 1;
  }

  if (ways[n] != -1) {
    return ways[n];
  }
  
  ways[n] = numWays_solution2(n - 1) + numWays_solution2(n - 2) + numWays_solution2(n - 3);
  //cout << n << ": " << ways[n] << endl;
 
  return ways[n];
}

int main(int argc, char** argv) {
  int n;
  cin >> n;
  init(n);
  cout << "Number of ways : " << numWays_solution2(n) << endl;
  return 0;
}
