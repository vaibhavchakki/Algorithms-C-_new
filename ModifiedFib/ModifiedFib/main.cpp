//
//  main.cpp
//  ModifiedFib
//
//  Created by Vaibhav Chakki on 8/30/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;

/*
 #include <iostream>
 #include <utility>
 
 #include <boost/multiprecision/cpp_int.hpp>
 
 using boost::multiprecision::cpp_int;
 
 cpp_int fib(cpp_int a, cpp_int b, unsigned int n)
 {
 for(unsigned int i = 2; i < n; ++i)
 {
 cpp_int temp = a + b*b;
 a = b;
 b = temp;
 }
 return b;
 }
 
 int main()
 {
 unsigned int a, b, n;
 
 std::cin >> a >> b >> n;
 std::cout << fib(a, b, n);
 }

 */


cpp_int fibMod(int t0, int t1, int n) {
    cpp_int t2_i;
    cpp_int t1_i = t1, t0_i = t0;
    while (n > 2) {
        t2_i = t0_i + (t1_i ** 2);
        t0_i = t1_i;
        t1_i = t2_i;
    }
    
    return t2_i;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t0, t1, n;
    cin >> t0 >> t1 >> n;
    
    cout << fibMod(t0, t1, n) << endl;
    
    return 0;
}
