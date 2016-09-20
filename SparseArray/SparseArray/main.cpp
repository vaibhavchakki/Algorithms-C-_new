//
//  main.cpp
//  SparseArray
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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, Q;
    string s;
    cin >> N;
    vector<string> str;
    vector<string> query;
    
    for (int i = 0; i < N; i++) {
        cin >> s;
        str.push_back(s);
    }
    
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> s;
        query.push_back(s);
    }
    
    vector<int> ans;
    for (int i = 0; i < Q; i++) {
        int match = 0;
        for (int j = 0; j < N; j++) {
            if (query.at(i) == str.at(j))
                match++;
        }
        ans.insert(ans.begin() + i, match);
    }
    
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
    
    return 0;
}

