//
//  main.cpp
//  GemStones
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

/*
 Suppose you have a String, , of length  that is indexed from  to . You also have some String, , that is the reverse of String .  is funny if the condition  is true for every character from  to .
 Input Format
 
 The first line contains an integer,  (the number of test cases).
 Each line  of the  subsequent lines contain a string, .
 
 Sample Input
 
 2
 acxz
 bcxz
 Sample Output
 
 Funny
 Not Funny
 Explanation

 */


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    
    vector <string> S;
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        S.push_back(str);
    }
    
    for (int i = 0; i < N; i++) {
        string str = S.at(i);
        int funny = 1;
        int len = str.length();
        for (int i = 0; i < len - 1; i++) {
            int diff_f = abs(str[i+1] - str[i]);
            int diff_b = abs(str[len - i - 1] - str[len - i - 2]);
            
            if (diff_f != diff_b) {
                funny = 0;
                break;
            }
        }
        if (funny) {
            cout << "Funny" << endl;
        }
        else {
            cout << "Not Funny" << endl;
        }
    }
    
    return 0;
}
