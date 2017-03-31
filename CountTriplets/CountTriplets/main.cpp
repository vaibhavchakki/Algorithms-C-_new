//
//  main.cpp
//  CountTriplets
//
//  Created by Vaibhav Chakki on 3/30/17.
//  Copyright © 2017 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

/*
 Given an array of distinct integers and a sum value. Find count of triplets with sum smaller than given sum value.
 */
int countTriplets(int arr[], int n, int sum) {
    int count = 0;
    
    if (n < 3) {
        return count;
    }
    
    //
    // First sort the array
    sort(arr, arr+n);
    
    for (int i = 0; i < n - 2; i ++) {
        
        int start = i + 1;
        int end = n - 1;
        
        while (start < end) {
            if ((arr[i] + arr[start] + arr[end]) >= sum) {
                end--;
            }
            else {
                count += (end - start);
                start++;
            }
        }
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {5, 1, 3, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 12;
    
    cout << countTriplets(arr, n, sum) << endl;
    
    return 0;
}
