#include <iostream>
#include <string.h>
using namespace std;

int lcs(char* A, char* B, int m, int n) {
    if ((m == 0) || (n == 0)) {
        return 0;
    }
   
    if (A[m - 1] == B[n - 1]) {
        return 1 + lcs(A, B, m - 1, n - 1);
    }

    return max(lcs(A, B, m - 1, n), lcs(A, B, m, n - 1));
}

int main(int argc, char** argv) {
    char* A = "ABCGHK";
    char* B = "AMBNC";

    cout << "LCS: " << lcs(A, B, strlen(A), strlen(B)) << endl;

    return 0;
}
