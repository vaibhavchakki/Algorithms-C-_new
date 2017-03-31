//
//  main.cpp
//  ZigZagArray
//
//  Created by Vaibhav Chakki on 3/30/17.
//  Copyright © 2017 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void zigZag_Solution1(int arr[], int n) {
    int i = 0;
    sort(arr, arr+n);
    
    for (i = 1; i < n - 1; i += 2) {
        swap(arr[i], arr[i+1]);
    }
    
    print_array(arr, n);
}

void zigZag_Solution2(int arr[], int n) {
    int flag = 1;
    
    for (int i = 0; i < n - 1; i++) {
        if (flag) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        else {
            if (arr[i] < arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        flag = !flag;
    }
    
    print_array(arr, n);
}

int main(int argc, const char * argv[]) {
    int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    //zigZag_Solution1(arr, n);
    zigZag_Solution2(arr, n);
    
    return 0;
}
