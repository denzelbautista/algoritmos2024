#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<pair<int, int>> freq;
    vector<int> topk;
    map<int, int> numsfrequency;
    for (int i = 0; i < nums.size(); i++) {
      numsfrequency[nums[i]]++;
    }

    for (const auto& e : numsfrequency) {
      freq.push_back({e.second, e.first});
    }

    make_heap(freq.begin(), freq.end());

    for (int i = 0; i < k; i++) {
      topk.push_back(freq[0].second);
      pop_heap(freq.begin(), freq.end());
      freq.pop_back();
    }

    return topk;
  }

  string decodeMessage(string key, string message) {
    string alf = "abcdefghijklmnopqrstuvwxyz";
    map<char, char> tabla;
    int i = 0;
    for (const char& cha : key) {
      if (cha == ' ') {
        tabla[' '] = ' ';
      } else if (tabla[cha] == '\0') {
        tabla[cha] = alf[i++];
      }
    }

    string decodedmessage = "";
    for (const char& c : message) {
      if (auto search = tabla.find(c); search != tabla.end()) {
        decodedmessage += search->second;
      }
    }
    return decodedmessage;
  }
};

void print(map<int, int> mp) {
  for (const auto& e : mp) {
    cout << e.first << " : " << e.second << endl;
  }
}

int main() {
  vector<int> v1 = {1, 1, 1, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4};
  vector<int> v2 = {1, 1, 1, 2, 2, 2, 3, 3, 3};
  vector<int> res;
  Solution s1;
  res = s1.topKFrequent(v2, 3);
  /*
    map<int, int> m1;
    vector<int> tpk;
    for (int i = 0; i < v1.size(); i++) {
      m1[v1[i]]++;
    }

    print(m1);
    */
  for (const auto& e : res) {
    cout << e << " ";
  }
  cout << endl;

  string a = s1.decodeMessage("the quick brown fox jumps over the lazy dog",
                              "vkbs bs t suepuv");
  cout << a << endl;

  return 0;
}