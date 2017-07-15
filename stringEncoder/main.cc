#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Encoder {
   map< char, vector<int> > tbl;
   string secret_;

   bool compare_(vector<int>& l, vector<int>& tl) const {
     if (l.size() != tl.size()) {
       return false;
     }
     for (int i = 0; i < l.size(); i++) {
       if (l[i] != tl[i]) {
         return false;
       }
     }
     return true;
   }

  public:
    Encoder(const string& s) {
      secret_ = s;
      for(int i = 0; i < s.length(); i++) {
        char c = s.at(i);
        tbl[c].push_back(i);
      }
    }

    bool isEncoded(const string& test) const {
      map < char, int > compared;
      if (test.length() != secret_.length()) {
         return false;
      }
 
      map< char, vector<int> > testTbl;
      for (int i = 0; i < test.length(); i++) {
        char c = test.at(i);
        testTbl[c].push_back(i);
      }

      for (int i = 0; i < test.length(); i++) {
        char c = test.at(i);
        char s = secret_.at(i);
        vector<int> l  = tbl.find(s)->second;
        vector<int> tl = testTbl.find(c)->second;

        if ( (compared.find(s) == compared.end()) && !compare_(l, tl) ) {
          return false;
        }
        compared[s] = 1;
      }
      return true;
    }
};


int main(int argc, char** argv) {
  Encoder obj(string("banana")); 
 
  cout << (obj.isEncoded(string("cololo")) ? "YES" : "NO") << endl;
  return 0;
}
