//
//  main.cpp
//  ReverseWords
//
//  Created by Vaibhav Chakki on 8/24/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char* strrev (char* s, char* e)
{
    char* start = s;
    char* end = e;
    
    while (start < end) {
        swap(*start++, *end--);
    }
    
    return s;
}

int main(int argc, const char * argv[]) {
    char str[] = " My name";
    
    strrev(str, str + strlen(str) - 1);
    
    size_t start = 0;
    
    for(int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            strrev(str + start, str + i - 1);
            start = i + 1;
        }
    }
    strrev (str + start, str + strlen(str) - 1);
    
    cout << str << endl;
    
}
