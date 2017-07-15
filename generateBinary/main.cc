#include<iostream>
using namespace std;

bool print(const string& s) {
   return (s.find('?') == string::npos);
}

void generateBinary(string& s, int index) {
  if (index > s.length()) {
    return;
  }
  for (int i = index; i < s.length(); i++) {
    if (s.at(i) == '?') {
      for (int j = 0; j < 2; j++) {
        s.at(i) = '0' + j;
        generateBinary(s, i + 1);
        if (print(s))
          cout << s << endl;
        s.at(i) = '?';
      }
    }
  }
}

int main(int argc, char** argv) {
  string s= "1??0?101";

  generateBinary(s, 0);
  
  return 0;
}
