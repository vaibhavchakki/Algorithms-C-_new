//
//  main.cpp
//  AlternatingCharacters
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


/* Shashank likes strings in which consecutive characters are different. For example, he likes ABABA, while he doesn't like ABAA. Given a string containing characters  and  only, he wants to change it into a string he likes. To do this, he is allowed to delete the characters in the string.

Your task is to find the minimum number of required deletions.
 Sample Input
 
 5
 AAAA
 BBBBB
 ABABABAB
 BABABA
 AAABBB
 Sample Output
 
 3
 4
 0
 0
 4
 Explanation
 
 AAAA  A, 3 deletions
 BBBBB  B, 4 deletions
 ABABABAB  ABABABAB, 0 deletions
 BABABA  BABABA, 0 deletions
 AAABBB  AB, 4 deletions because to convert it to AB we need to delete 2 A's and 2 B's
 
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    string str;
    vector <string> S;
    vector <int> ans;
    
    for(int i = 0; i < N; i++) {
        cin >> str;
        S.push_back(str);
    }
    
    for (int i = 0; i < N; i++) {
        str = S.at(i);
        int change = 0;
        for (int l = 0; l < str.length() - 1; l++) {
            if (str[l] == str[l + 1]) {
                change++;
            }
        }
        ans.push_back(change);
    }
    
    for (int i = 0; i < N; i++) {
        cout << ans.at(i) << endl;
    }
    
    return 0;
}
