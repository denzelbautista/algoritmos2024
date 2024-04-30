#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void push_front(ListNode*& head, int val) {
  ListNode* nuevo = new ListNode(val);
  if (head->val == 0 && head->next == nullptr) {
    head = nuevo;
  } else {
    nuevo->next = head;
    head = nuevo;
  }
}

void imprimir(ListNode*& head) {
  ListNode* temp = head;
  while (temp != nullptr) {
    cout << temp->val << " -> ";
    temp = temp->next;
  }
  cout << endl;
}
ListNode* invertir(ListNode*& normal) {
  ListNode* invertida = new ListNode(normal->val);
  ListNode* second = normal->next;
  while (second != nullptr) {
    push_front(invertida, second->val);
    second = second->next;
  }
  return invertida;
}

int mayor(ListNode* l1, ListNode* l2) {
  int c1 = 0;
  int c2 = 0;
  ListNode* t1 = l1;
  ListNode* t2 = l2;
  while (t1 != nullptr) {
    c1 += 1;
    t1 = t1->next;
  }
  while (t2 != nullptr) {
    c2 += 1;
    t2 = t2->next;
  }
  return c1 > c2 ? c1 : c2;
}

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l1i = invertir(l1);
    ListNode* l2i = invertir(l2);
    int digitos = mayor(l1i, l2i);
    ListNode* result = new ListNode();
    int suma = 0;
    int carry = 0;
    for (int i = 0; i < digitos; i++) {
      suma = l1i->val + l2i->val;
      push_front(result, suma % 10 + carry);
      carry = 0;
      if (suma >= 10) {
        carry = 1;
      }
      // Logica de cuando uno es meyor que otro
      if (l1i->next == nullptr) {
        ListNode* sig = new ListNode(0);
        l1i->next = sig;
      }
      l1i = l1i->next;
      if (l2i->next == nullptr) {
        ListNode* sig2 = new ListNode(0);
        l2i->next = sig2;
      }
      l2i = l2i->next;
    }
    return result;
  }
};

int main() {
  ListNode* l1 = new ListNode(3);
  push_front(l1, 4);
  push_front(l1, 2);
  push_front(l1, 7);

  ListNode* l2 = new ListNode(4);
  push_front(l2, 6);
  push_front(l2, 5);

  Solution s1;
  ListNode* res = s1.addTwoNumbers(l1, l2);
  imprimir(res);

  return 0;
}