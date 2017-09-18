/*
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z 
 * where different letters represent different tasks.Tasks could be done without original order. 
 * Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be 
 * at least n intervals that CPU are doing different tasks or just be idle.
 * 
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 * 
 * Example 1:
 * Input: tasks = ['A','A','A','B','B','B'], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 * https://leetcode.com/problems/task-scheduler/description/
 */
#include <iostream>
#include <vector>
using namespace std;


int leastInterval(vector<char>& tasks, int n) {
  // create a map to store the tasks, its size if 26 because number of characters
  int map[26];
  vector<int> q;
  
  // set the count for each element in map to 0
  memset(map, 0, sizeof(map));
  
  // count each different tasks
  for (int i = 0; i < tasks.size(); i++) {
    map[tasks[i] - 'A']++;
  }
  
  // store the tasks in Q
  for (int i = 0; i < 26; i++) {
    if (map[i] > 0) {
      q.push_back(map[i]);
    }
  }
  
  // sort the 'Q' in descending order
  sort(q.begin(), q.end(), greater<int>());
  
  // initialize the totaltime to 0
  int totalTime = 0;
  
  // if top of 'Q' is > 0, then there are pending tasks still
  while (q[0] > 0) {
    for (int i = 0; i <= n; i++) {
      // if top of the q is 0, then break from the loop
      if (q[0] == 0) {
        break;
      }
          
      if ( (i < 26) &&   // max different tasks is 26, because of number of characters
           (i < q.size()) && (q[i] > 0) ) { // if i is less than size and has any tasks
         q[i]--;
      }
      totalTime++;
    }

    // resort the 'Q' after changing the contents of it
    sort(q.begin(), q.end(), greater<int>());
  }
  return totalTime; 
}

int main() {
  char tasks[] = {'A', 'A', 'A', 'B', 'B', 'B'};
  vector<char> t(tasks, tasks + 6);
  int n = 2;

  cout << "Total time = " << leastInterval(t, n) << endl;

  return 0;
}
