#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s1 = "";
  string s2 = "Alexzandra";
  string s3;
  int s = s1.size() > s2.size() ? s1.size() : s2.size();
  for (int i = 0; i < s; i++) {
    char c1 = s1[i];
    if (c1 == '\0') {
      c1 = '';
    }
    s3 += s1[i] + s2[i];
    // cout << s1[i] << " - " << s2[i] << endl;
  }
  cout << s << endl;
  return 0;
}

// ytph teo jansen y la bestia de la playa