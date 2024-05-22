template <typename T>
class ForwardList {
 private:
  struct Node {
   private:
    T data;
    Node* next;
  }
};

template <typename T>
class CircularList {
 private:
  struct Node {
    T data;
    Node* next;
    Node* prev;
    Node() { next = prev = nullptr; }
    Node(T data, Node* next = nullptr, Node* prev = nullptr) {
      data->data;
      next->next;
      prev->prev;
    }
  };
  Node* head;  // Sentinel node

 public:
  CircularList() {
    head = new Node();
    head->next = head;
    head->prev = head;
  }

  void push_front(T data) {
    Node* nuevo = new Node(data);
    nuevo->next = head->next;
    nuevo->prev = head;
    head->next->prev = nuevo;
    head->next = nuevo;
  }

  void push_back(T data) {
    Node* nuevo = new Node(data);
    nuevo->next = head;
    nuevo->prev = head->prev;
    head->prev->next = nuevo;
    head->prev = nuevo;
  }

  T pop_front() {
    Node* nodetodelete = head->next;
    T data = nodetodelete->data;
    head->next = nodetodelete->next;
    nodetodelete->next->prev = head;
    delete nodetodelete;
    return data;
  }

  T pop_back() {
    Node* nodetodelete = head->prev;
    T data = nodetodelete->data;
    nodetodelete->prev->next = head;
    head->prev = nodetodelete->prev;
    delete nodetodelete;
    return data;
  }

  void display() {
    Node* temp = head->next;
    while (temp != head) {
      cout << temp->data << " ";
      temp = temp->next;
    }
  }
};