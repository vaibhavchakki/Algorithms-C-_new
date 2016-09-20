//
//  main.cpp
//  BinarySearch
//
//  Created by Vaibhav Chakki on 8/25/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>

using namespace std;

bool Find(int* arr, int n, int num)
{
    bool found = false;
    int  first = 0;
    int  last  = n;

    while ((first <= last)&& !found) {
        int mid = (first + last) / 2;
        
        if (arr[mid] == num) {
            found = true;
        }
        else if (num < arr[mid]) {
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    
    return found;
}

int main(int argc, const char * argv[]) {

    int arr[] = {0, 2, 5, 6, 8, 12, 20, 56};
    
    cout << Find(arr, 8, 5) << endl;
    
}
