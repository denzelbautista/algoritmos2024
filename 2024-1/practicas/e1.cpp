#include <iostream>
#include <map>
#include <set>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
  void nextnode(ListNode* _next) { next = _next; }
};

void hascicle(ListNode* head) {
  ListNode* temp = head;
  multimap<ListNode*, int> nodes;
  int index = 0;
  int pos = -1;
  while (temp->next != nullptr) {
    nodes.insert({temp, index});
    if (auto search = nodes.find(temp->next); search != nodes.end()) {
      pos = search->second;
      break;
    }
    temp = temp->next;
    index += 1;
  }
  cout << "tail connect to node index " << pos << endl;
}

int main() {
  /*
ListNode* l2 = new ListNode(2);
ListNode* l4 = new ListNode(4);
ListNode* l0 = new ListNode(0);
ListNode* l3 = new ListNode(3);
l3->nextnode(l2);
l2->nextnode(l0);
l0->nextnode(l4);
l4->nextnode(l2);
*/
  ListNode* l1 = new ListNode(1);
  ListNode* l2 = new ListNode(2);
  l1->nextnode(l2);
  l2->nextnode(l1);
  // l3 es el head;
  hascicle(l1);
  return 0;
}
