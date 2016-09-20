//
//  main.cpp
//  Pangram
//
//  Created by Vaibhav Chakki on 8/28/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

char tolowercase(char c)
{
    if (c >= 'A' && c <= 'Z') {
        c = c - ('Z' - 'z');
    }
    return c;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    string str;
    getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), tolowercase);
    
    map<char, int> charMap;
    
    for(size_t i = 0; i < str.length(); i++) {
        if (str.at(i) != ' ') {
            charMap[str.at(i)] = 1;
        }
    }
    
    if (charMap.size() == (('z' - 'a') + 1)) {
        cout << "pangram";
    }
    else {
        cout << "not pangram";
    }
    
    
    return 0;
}
