//
//  main.cpp
//  swapEvenAndOdd
//
//  Created by Vaibhav Chakki on 8/27/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
using namespace std;

unsigned int swapEvenAndOdd(unsigned int N)
{
    unsigned int even_bits = N & 0xAAAAAAAA;
    unsigned int odd_bits  = N & 0x55555555;
    
    return ((even_bits >> 1) | (odd_bits << 1));
    
}

int main(int argc, const char * argv[]) {

    unsigned int N = 23;
    
    cout << swapEvenAndOdd(N) << endl;
    
    return 0;
}
