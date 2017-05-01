#include <iostream>
using namespace std;

typedef unsigned int uint32;

uint32 fib1(uint32 n) {
    if (n < 2) {
        return n;
    }
    return fib1(n - 1) + fib1(n - 2);
}

uint32 fib2(uint32 n) {
    uint32 sum = 1, prev_sum = 1;
    if (n < 2) {
        return n;
    }
    for (int i = 2; i <= n; i++) {
	uint32 t = sum;
	sum += prev_sum;
	prev_sum = t;
    }
    return sum;
}

int main(int argc, char** argv) {
    uint32 n;
    cin >> n;

    cout << "Fib 1: " << fib1(n) << endl;
    cout << "Fib 2: " << fib2(n) << endl;
    return 0;
}
