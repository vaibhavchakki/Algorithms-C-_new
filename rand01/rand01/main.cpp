//
//  main.cpp
//  rand01
//
//  Created by Vaibhav Chakki on 8/27/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
using namespace std;

unsigned int rand50()
{
    return rand() & 1;
}


//
// Return 1 with 75% prob and 0 with 25% prob
unsigned int rand75()
{
    return rand50() | rand50();
}

//
// Return 1 with 25% prob and 0 with 75% prob
unsigned int rand25()
{
    return rand50() & rand50();
}


int main(int argc, const char * argv[]) {

    for (int i = 0; i < 20; i++) {
        cout << rand25() << endl;
    }
    return 0;
}
