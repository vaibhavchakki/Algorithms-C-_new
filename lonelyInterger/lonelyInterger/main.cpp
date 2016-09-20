//
//  main.cpp
//  lonelyInterger
//
//  Created by Vaibhav Chakki on 8/28/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;


int lonelyinteger2(vector<int> a)
{
    int ans = 0;
    for (auto i = a.begin(); i != a.end(); i++) {
        ans ^= *i;
    }
    
    return ans;
}

int lonelyinteger1(vector < int > a) {
    
    map<int, int> intMap;
    
    for (auto i = a.begin(); i != a.end(); i++) {
        int num = *i;
        auto j = intMap.find(*i);
        
        if (intMap.end() == j) {
            intMap[num] = 1;
        }
        else {
            intMap[num] += 1;
        }
    }
    
    for (auto i = intMap.begin(); i != intMap.end(); i++) {
        if ((*i).second == 1) {
            return (*i).first;
        }
    }
    
    return -1;
}

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger2(_a);
    cout << res << endl;
    
    return 0;
}