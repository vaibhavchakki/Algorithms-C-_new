//
//  main.cpp
//  InsertionSort
//
//  Created by Vaibhav Chakki on 8/30/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;

void print(int size, int* ar) {
    for (int i = 0; i < size; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

void insertionSort(int ar_size, int *  ar) {
    /*
     We begin by assuming that a list with one item (position 00) is already sorted. On each pass, one for each item 1 through n−1n−1, the current item is checked against those in the already sorted sublist. As we look back into the already sorted sublist, we shift those items that are greater to the right. When we reach a smaller item or the end of the sublist, the current item can be inserted.
     */
    
    /*
     start with element 1, since element 0 is already sorted
     */
    for (int i = 1; i < ar_size; i++) {
        int currvalue = ar[i];
        int position = i;
        
        while ((position > 0) && (ar[position - 1] > currvalue)) {
            ar[position] = ar[position - 1];
            //print(ar_size, ar);
            position--;
        }
        ar[position] = currvalue;
        print(ar_size, ar);
    }
}

int main(void) {
    
    int _ar_size;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) {
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]);
    }
    
    insertionSort(_ar_size, _ar);
    
    return 0;
}
