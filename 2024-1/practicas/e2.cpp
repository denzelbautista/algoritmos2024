#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
  void nextnode(ListNode* _next) { next = _next; }
};

void print(ListNode* head) {
  ListNode* current = head;
  while (current != nullptr) {
    cout << current->val << " ";
    current = current->next;
  }
}

class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    // Initialize a dummy node to simplify merging
    ListNode dummy(0);
    ListNode* sorted = &dummy;

    // Priority queue to keep track of the smallest value from each list
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                   greater<pair<int, ListNode*>>>
        pq;

    // Add the heads of all linked lists to the priority queue
    for (ListNode* head : lists) {
      if (head) {
        pq.push({head->val, head});
      }
    }

    // Merge the lists
    while (!pq.empty()) {
      auto [val, node] = pq.top();
      pq.pop();

      sorted->next = node;
      sorted = sorted->next;

      if (node->next) {
        pq.push({node->next->val, node->next});
      }
    }

    return dummy.next;
  }
};

int main() {
  ListNode* l1 = new ListNode(1);
  ListNode* l4 = new ListNode(4);
  ListNode* l5 = new ListNode(5);
  l1->nextnode(l4);
  l4->nextnode(l5);
  //
  ListNode* l1_2 = new ListNode(1);
  ListNode* l4_2 = new ListNode(4);
  ListNode* l3 = new ListNode(3);
  l1_2->nextnode(l3);
  l3->nextnode(l4_2);
  //
  ListNode* l2 = new ListNode(2);
  ListNode* l6 = new ListNode(6);
  l2->nextnode(l6);
  vector<ListNode*> l = {l1, l1_2, l2};
  Solution s1;

  ListNode* head;
  head = s1.mergeKLists(l);
  print(head);
  cout << endl;
}