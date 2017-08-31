#include <iostream>

using namespace std;

int main(int argc, char** argv) {
  int nRows = 0;
 
  cin >> nRows;

  if ( nRows < 1 ) {
    return 0;
  }

  int val = 1;

  for (int i = 1; i <= nRows; i++) {
    for (int j = 0; j < i; j++) {
      cout << val << " ";
      val++;
    }
    cout << endl;
  }

  return 0;
}
