#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

void findSubString(char *S, char *F) {
  int lenF = strlen(F);
  int lenS = strlen(S);

  if (lenS > lenF) {
    cout << "Substring not found\n";
    return;
  } 
  else {
    vector <int> res;
    for(int i = 0; i <= (lenF - lenS); i++) {
      bool found = true;
      for (int j = 0; j < lenS; j++) {
        if (S[j] != F[i + j]) {
          found = false;
          break;
        }
      }
      if (found) {
        res.push_back(i);
      }
    }
    for (auto itr = res.begin(); itr != res.end(); itr++) {
      cout << *itr << endl;
    }
  }

}


int main(int argc, char** argv) {
  char fullString[] = "AAAAA";
  char findString[] = "A";

  findSubString(findString, fullString);
  return 0;
}
