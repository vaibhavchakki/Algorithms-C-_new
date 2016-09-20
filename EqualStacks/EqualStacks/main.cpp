//
//  main.cpp
//  EqualStacks
//
//  Created by Vaibhav Chakki on 8/29/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

/*
 You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times.
 
 Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they're all the same height, then print the height. The removals must be performed in such a way as to maximize the height.
 
 Output Format
 
 Print a single integer denoting the maximum height at which all stacks will be of equal height.
 
 Sample Input
 
 5 3 4
 3 2 1 1 1
 4 3 2
 1 1 4 1
 Sample Output
 
 5
 
 */

using namespace std;


int main(){
    int n1;
    int n2;
    int n3;
    cin >> n1 >> n2 >> n3;
    vector<int> h1(n1);
    int sum1 = 0;
    for(int h1_i = 0;h1_i < n1;h1_i++){
        cin >> h1[h1_i];
        sum1 += h1[h1_i];
    }
    vector<int> h2(n2);
    int sum2 = 0;
    for(int h2_i = 0;h2_i < n2;h2_i++){
        cin >> h2[h2_i];
        sum2 += h2[h2_i];
    }
    vector<int> h3(n3);
    int sum3;
    for(int h3_i = 0;h3_i < n3;h3_i++){
        cin >> h3[h3_i];
        sum3 += h3[h3_i];
    }
    
    while ((sum1 != sum2) || (sum2 != sum3) || (sum3 != sum1)) {
        if (sum1 > sum2) {
            sum1 = sum1 - h1.front();
            h1.erase(h1.begin());
        }
        else if (sum2 > sum1) {
            sum2 = sum2 - h2.front();
            h2.erase(h2.begin());
        }
        
        if (sum2 > sum3) {
            sum2 = sum2 - h2.front();
            h2.erase(h2.begin());
        }
        else if (sum3 > sum2) {
            sum3 = sum3 - h3.front();
            h3.erase(h3.begin());
        }
        
        if (sum3 > sum1) {
            sum3 = sum3 - h3.front();
            h3.erase(h3.begin());
        }
        else if (sum1 > sum3) {
            sum1 = sum1 - h1.front();
            h1.erase(h1.begin());
        }
    }
    
    cout << sum1 << endl;
    
    return 0;
}

