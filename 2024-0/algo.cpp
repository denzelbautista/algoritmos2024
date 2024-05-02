#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int count = 0;
  map<char, int> mpkey;
  for (const char c : "the quick brown fox jumps over the lazy dog") {
    if (c != ' ') {
      if (mpkey.find(c) != mpkey.end()) {
      } else {
        mpkey.insert({c, count});
        count++;
      }
    }
  }
  map<char, int> alphabet;
  int in = 0;
  for (const char c : "abcdefghijklmnopqrstuvwxyz") {
    alphabet[c] = in;
    in++;
  }
  string newm = "";
  for (const char c : "vkbs bs t suepuv") {
    newm += 'a';
  }

  for (const auto& [key, value] : mpkey) {
    // cout << key << " : " << value << "\n";
  }

  cout << newm << endl;
  return 0;
}