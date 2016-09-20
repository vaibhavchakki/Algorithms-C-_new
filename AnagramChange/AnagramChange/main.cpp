//
//  main.cpp
//  AnagramChange
//
//  Created by Vaibhav Chakki on 8/31/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 Sid is obsessed with reading short stories. Being a CS student, he is doing some interesting frequency analysis with the books. He chooses strings  and  in such a way that .
 
 Your task is to help him find the minimum number of characters of the first string he needs to change to enable him to make it an anagram of the second string.
 
 Note: A word x is an anagram of another word y if we can produce y by rearranging the letters of x.
 
 https://www.hackerrank.com/challenges/anagram
 
 Sample Input
 
 6
 aaabbb
 ab
 abc
 mnop
 xyyx
 xaxbbbxx
 Sample Output
 
 3
 1
 -1
 2
 0
 1
 */

int getAnagramCount(string s) {
    int change1['z' - 'a' + 1] = {0};
    int len = s.length();
    
    if (len % 2)
    {
        return -1;
    }
    
    for (int i = 0; i < len; i++) {
        if (i < len/2) {
            change1[s[i] - 'a']++;
        }
        else {
            change1[s[i] - 'a']--;
        }
    }
    
    int ch = 0;
    for (int i = 0; i <= ('z' - 'a'); i++) {
        if (change1[i] > 0) {
            ch += change1[i];
        }
    }
    
    return ch;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    
    vector <string> S(N);
    
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    
    for (int i = 0; i < N; i++) {
        cout << getAnagramCount(S[i]) << endl;
    }
    
    return 0;
}