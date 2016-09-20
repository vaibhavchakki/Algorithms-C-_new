//
//  main.cpp
//  toBinary
//
//  Created by Vaibhav Chakki on 8/27/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>

using namespace std;

void toBinary(unsigned int n)
{
    if (n > 1) {
        toBinary(n / 2);
    }
    
    cout << (n & 1);
}

int main(int argc, const char * argv[]) {

    toBinary(9);
    cout << endl;
    return 0;
}
