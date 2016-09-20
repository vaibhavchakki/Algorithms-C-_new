//
//  main.cpp
//  MaximumSubArray
//
//  Created by Vaibhav Chakki on 8/30/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void printMaxSum(vector <int> arr) {
    int prevSum = INT_MIN;
    int contSum = INT_MIN;
    int nonContSum = INT_MIN;
    
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            nonContSum = arr[i];
            contSum = arr[i];
            prevSum = arr[i];
        }
        else {
            prevSum = max(prevSum + arr[i], arr[i]);
            contSum = max(contSum, prevSum);
            
            if ((arr[i] + nonContSum) > nonContSum) {
                nonContSum = arr[i] + nonContSum;
            }
            else if (nonContSum < arr[i]) {
                nonContSum = arr[i];
            }
        }
    }
    cout << contSum << " " << nonContSum << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, L;
    cin >> N;
    
    vector < vector<int> > tests(N);
    
    for (int i = 0; i < N; i++) {
        cin >> L;
        for (int j = 0; j < L; j++) {
            int num;
            cin >> num;
            tests[i].push_back(num);
        }
    }
    
    for (int i = 0; i < N; i++) {
        printMaxSum(tests[i]);
    }
    
    return 0;
}

