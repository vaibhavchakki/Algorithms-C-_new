//
//  main.cpp
//  Paranthesis-Matching
//
//  Created by Vaibhav Chakki on 7/13/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool isMatching(char s, char e)
{
    if ( (s == '{' && e == '}') ||
         (s == '(' && e == ')') ||
         (s == '[' && e == ']') )
        return true;
    else
        return false;
}


int main(int argc, const char * argv[]) {
    char exp[] = "{([]{})()}}";
    vector<char> S;
    
    for(int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            S.push_back(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
            char e;
            
            if (!S.empty())
                e = S.back();
            
            if (S.empty() || !isMatching(e, exp[i])) {
                cout << "Not matching\n";
                return -1;
            }
            S.pop_back();
        }
        else {
            cout << "Invalid character\n";
            return -1;
        }
    }
    
    if (!S.empty()) {
        cout <<"Not matching\n";
    }
    else {
        cout << "Matching\n";
    }
    
    return 0;
}
