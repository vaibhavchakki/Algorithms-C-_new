//
//  main.cpp
//  FunnyString
//
//  Created by Vaibhav Chakki on 8/29/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


/*
 Input Format
 
 The first line consists of an integer, , the number of rocks.
 Each of the next  lines contains a rock's composition. Each composition consists of lower-case letters of English alphabet.
 
 Sample Input
 
 3
 abcdde
 baccd
 eeabg
 
 Sample Output
 
 2
 Explanation
 
 Only "a" and "b" are the two kinds of gem-elements, since these are the only characters that occur in every rock's composition.
 
 
 */


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    
    vector <string> S;
    
    map<char, int> charMap;
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        S.push_back(str);
    }
    
    for (int i = 0; i < N; i++) {
        string str = S.at(i);
        
        for (int j = 0; j < str.length(); j++) {
            if (charMap.find(str[j]) == charMap.end()) {
                if (i == 0) {
                    charMap[str[j]] = 1;
                }
            }
            else {
                if (charMap[str[j]] == i) {
                    charMap[str[j]] = i + 1;
                }
            }
        }
    }
    int count = 0;
    for (auto i = charMap.begin(); i != charMap.end(); i++) {
        if (i->second == N) {
            count++;
        }
    }
    
    
    cout << count << endl;
    
    return 0;
}
