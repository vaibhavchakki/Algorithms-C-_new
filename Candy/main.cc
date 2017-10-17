/*
 * There are N children standing in a line. Each child is assigned a rating value.
 * You are giving candies to these children subjected to the following requirements:
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * What is the minimum candies you must give?
 */
#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }    
  cout << endl;
}

int candy(vector<int>& ratings) {
  vector<int> leftCount = vector<int>(ratings.size(), 1);
  vector<int> rightCount = vector<int>(ratings.size(), 1);
    
  for (int i = 1; i < ratings.size(); i++) {
    if (ratings[i] > ratings[i-1]) {
      leftCount[i] = leftCount[i-1] + 1;
    }
  }
    
  //print(leftCount);
    
  for (int i = ratings.size() - 2; i >= 0; i--) {
    if (ratings[i] > ratings[i+1]) {
      rightCount[i] = rightCount[i+1] + 1;
    }
  }
    
  //print(rightCount);
    
  int result = 0;
  for (int i = 0; i < ratings.size(); i++) {
    result += max(leftCount[i], rightCount[i]);
  }
    
  return result;
}

int main(int argc, const char** argv) {
  int ratings[] = {1, 3, 2, 6, 4};
  vector<int> r(ratings, ratings+5);

  cout << "Min candy is: " << candy(r) << endl;
  
  return 0;
}
