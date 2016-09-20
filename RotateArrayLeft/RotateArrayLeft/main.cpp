//
//  main.cpp
//  RotateArrayLeft
//
//  Created by Vaibhav Chakki on 8/29/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void reverseArray(vector<int>& arr, int s, int e)
{
    while (s < e) {
        swap(arr[s++], arr[e--]);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, d, in;
    cin >> n >> d;
    vector <int> arr;
    
    for (int i = 0; i < n; i++) {
        cin >> in;
        arr.push_back(in);
    }
    
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, n - (d % n) - 1);
    reverseArray(arr, n - (d % n), n - 1);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
