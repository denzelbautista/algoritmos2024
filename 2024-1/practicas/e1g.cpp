#include <iostream>
using namespace std;

// Definición de la estructura ListNode
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Función para detectar el ciclo y encontrar su inicio
void detectCycle(ListNode* head) {
  if (head == nullptr || head->next == nullptr) {
    cout << "No cycle in the list" << endl;
    return;
  }

  ListNode* slow = head;
  ListNode* fast = head;

  // Paso 1: Detectar si hay un ciclo
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      // Paso 2: Encontrar el inicio del ciclo
      slow = head;
      int pos = 0;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
        pos++;
      }
      cout << "Tail connects to node index " << pos << endl;
      return;
    }
  }

  cout << "No cycle in the list" << endl;
}

int main() {
  // Crear una lista con un ciclo para pruebas
  ListNode* head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;  // Crear ciclo

  // Detectar el ciclo y encontrar su inicio
  detectCycle(head);

  // Liberar la memoria (en un entorno real, debemos eliminar la lista
  // adecuadamente) Aquí no eliminamos los nodos porque hay un ciclo que puede
  // causar una doble eliminación.

  return 0;
}
