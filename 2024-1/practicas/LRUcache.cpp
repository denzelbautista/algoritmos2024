#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class LRUCache {
 private:
  int capacity;
  unordered_map<int, int> cache;  // para todos
  list<int> lru;                  // para los usos recientes

 public:
  LRUCache(int _capacity) { capacity = _capacity; }
  int get(int key) {
    if (auto search = cache.find(key); search != cache.end()) {
      if (search->first != lru.front()) {
        lru.remove(search->first);
        lru.push_front(search->first);
      }
      return search->second;
    }
    return -1;
  }

  void put(int key, int value) {
    if (auto search = cache.find(key); search != cache.end()) {
      cache[key] = value;
      lru.remove(key);
      lru.push_front(key);
    } else {
      if (cache.size() == capacity) {
        cache.erase(lru.back());
        lru.pop_back();
      }
      cache[key] = value;
      lru.push_front(key);
    }
  }
};

int main() {
  LRUCache *l1 = new LRUCache(2);
  l1->put(1, 1);
  l1->put(2, 2);
  cout << l1->get(1) << endl;
  l1->put(3, 3);
  cout << l1->get(2) << endl;
  l1->put(4, 4);
  cout << l1->get(1) << endl;
  cout << l1->get(3) << endl;
  cout << l1->get(4) << endl;

  return 0;
}