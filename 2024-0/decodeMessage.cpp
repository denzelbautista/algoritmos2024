#include <cassert>
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
 public:
  string decodeMessage(string key, string message) {
    string decmes = "";
    string newkey = "";
    int count = 0;
    map<int, char> mpkey;
    for (const char c : key) {
      if (c != ' ') {
        if (mpkey.find(c) != mpkey.end()) {
        } else {
          mpkey.insert({c, count++});
        }
      }
    }

    map<int, char> alphabet;
    for (const char c : "abcdefghijklmnopqrstuvwxyz") {
      alphabet[c]++;
    }

    return decmes;
  }
};

void test() {
  assert(Solution().decodeMessage("the quick brown fox jumps over the lazy dog",
                                  "vkbs bs t suepuv") == "this is a secret");
  assert(Solution().decodeMessage("eljuxhpwnyrdgtqkviszcfmabo",
                                  "zwx hnfx lqantp mnoeius ycgk vcnjrdb") ==
         "the five boxing wizards jump quickly");
  assert(Solution().decodeMessage(
             "algorimos abc defghi jkl mno pqrstu vwxyz datos",
             "holamundoutec") == "ndbaguqkdutlj");
  assert(Solution().decodeMessage("abcdefghijklmnopqrstuvwxyz",
                                  "i love lourdes") == "i love lourdes");
}

int main() {
  // test();
  map<int, string> nom;
  nom.insert({1, "Denzel"});

  nom.insert({2, "Ale"});

  for (const auto &[key, value] : nom) {
    if (value == "Denzel")
      cout << "Se encontró a Denzel"
           << "con el key de " << key << endl;
  }

  map<string, string> users;

  users.insert(make_pair("70876054", "Denzel"));
  users.insert(make_pair("08328741", "Hector"));

  auto it = users.find("08327841");

  if (it != users.end())  // tambien se puede utilizar un iterador
  {
    cout << "Se encontró el DNI" << it->first << " que pertenece a "
         << it->second << endl;
  } else {
    cout << "Denzel no está" << endl;
  }

  return 0;
}
