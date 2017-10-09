/*
 * Given an integer array with even length, where different numbers in this array represent different 
 * kinds of candies. Each number means one candy of the corresponding kind. You need to distribute 
 * these candies equally in number to brother and sister. Return the maximum number of kinds of candies 
 * the sister could gain.
 * 
 * Example 1:
 * Input: candies = [1,1,2,2,3,3]
 * Output: 3
 * Explanation:
 * There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
 * Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
 * The sister has three different kinds of candies. 
 * Example 2:
 * Input: candies = [1,1,2,3]
 * Output: 2
 * Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
 * The sister has two different kinds of candies, the brother has only one kind of candies. 
 */
#include <iostream>
using namespace std;

int distributeCandies(vector<int>& candies) {
    map<int, int> diff;
    int num_b = 0;
    int num_s = 0;
    set<int> br;
    set<int> ss;
    
    /*for (int i = 0; i < candies.size(); i++) {
        
        if (num_s < candies.size() / 2) {
            if (diff.find(candies[i]) == diff.end()) {
                ss.insert(candies[i]); num_s++;
                diff[candies[i]] = 1;
             }
             else {
                 br.insert(candies[i]); num_b++;
             }
        }
        else {
            if (num_s < num_b) {
                ss.insert(candies[i]); num_s++;
            }
            else {
                br.insert(candies[i]); num_b++;
            }
        }
    }
    return ss.size();*/
    
    set<int> kinds;
    for (int i = 0; i < candies.size(); i++) {
        kinds.insert(candies[i]);
    }
    
    return min(candies.size() / 2, kinds.size());
}

int main(int argc, const char** argv) {
  return 0;
}
