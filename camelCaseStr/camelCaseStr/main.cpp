//
//  main.cpp
//  camelCaseStr
//
//  Created by Vaibhav Chakki on 8/28/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool isUpper(const char& c)
{
    return ((c >= 'A') && (c <= 'Z'));
}


int main(){
    string s;
    cin >> s;
    int wordCount = 0;
    
    int len = s.length();
    
    if (len) {
        wordCount++;
    }
    
    
    while (len - 1) {
        if (isUpper(s.at(len-1))) {
            wordCount++;
        }
        len--;
    }
    
    cout << wordCount;
    return 0;
}