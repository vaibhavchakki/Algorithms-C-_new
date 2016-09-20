//
//  main.cpp
//  MaxStockProfit
//
//  Created by Vaibhav Chakki on 8/27/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>

using namespace std;

unsigned long getMaxProfit(int* arr, size_t l)
{
    unsigned long profit = 0;
    unsigned long min = arr[0];

    for (size_t i = 1; i < l - 1; i++) {
        
        min = (arr[i] < min) ? arr[i] : min;
        
        if ((min < arr[i]) && (arr[i] > arr[i+1])) {
            profit += arr[i] - min;
            min = arr[i+1];
        }
    }
    
    if (min < arr[l - 1]) {
        profit += arr[l - 1] - min;
    }

    return profit;
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {100, 180, 260, 310, 40, 535, 695};
    
    cout << getMaxProfit(arr, 7) << endl;
    return 0;
}
