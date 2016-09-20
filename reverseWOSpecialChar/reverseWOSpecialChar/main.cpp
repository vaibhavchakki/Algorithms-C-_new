//
//  main.cpp
//  reverseWOSpecialChar
//
//  Created by Vaibhav Chakki on 8/27/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
using namespace std;

bool isAlphabet(char C) {
    
    return ((C >= 'A' && C <= 'Z') ||
            (C >= 'a' && C <= 'z'));
}

int main(int argc, const char * argv[]) {
    char str[] = "a!!!b.c.d,e'f,ghi";
    
    cout << "Input string " << str << endl;
    size_t start = 0;
    size_t end = strlen(str) - 1;
    
    while (start < end) {
        if (!isAlphabet(str[start])) {
            start++;
        }
        else if (!isAlphabet(str[end])) {
            end--;
        }
        else {
            swap(str[start], str[end]);
            start++;
            end--;
        }
    }
    
    cout << "Reversed String " << str << endl;
    
    return 0;
}
