//
//  main.cpp
//  SuperReducedString
//
//  Created by Vaibhav Chakki on 8/28/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
 Shil has a string, , consisting of  lowercase English letters. In one operation, he can delete any pair of adjacent letters with same value. For example, string "" would become either "" or "" after  operation.
 
 Shil wants to reduce  as much as possible. To do this, he will repeat the above operation as many times as it can be performed. Help Shil out by finding and printing 's non-reducible form!
 
 Note: If the final string is empty, print .
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    string str;
    cin >> str;
    
    while (1) {
        size_t len = str.length();
        int update = 0;
        
        for (size_t i = 0; i < len - 1; i++) {
            if (str[i] == str[i+1]) {
                str.erase(i, 2);
                update = 1;
            }
        }
        
        if (!update) {
            break;
        }
    }
    
    if (str.length() > 0)
        cout << str;
    else
        cout << "Empty String";
    
    return 0;
}
