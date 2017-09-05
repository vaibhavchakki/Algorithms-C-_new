#include <iostream>
#include <assert.h>
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

/*
 * Fib using dynamic programming
 */
int N = 100;
int *lookup = NULL;
void initialize() {
  lookup = new int(N);
  for (int i = 0; i < N; i++) {
    lookup[i] = -1;
  }
}

uint32 fib3(uint32 n) {
  assert(lookup);
  if (lookup[n] == -1) {
    if (n < 2) {
      lookup[n] = n;
    }
    else {
      lookup[n] = fib3(n-1) + fib3(n-2);
    }
  }
  return lookup[n];
}

int main(int argc, char** argv) {
    uint32 n;
    cin >> n;

    initialize();
    cout << "Fib 1: " << fib1(n) << endl;
    cout << "Fib 2: " << fib2(n) << endl;
    cout << "Fib 3: " << fib3(n) << endl;
    return 0;
}
