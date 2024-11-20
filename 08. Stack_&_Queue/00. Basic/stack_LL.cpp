#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

class Stack {
  Node *top;

 public:
  Stack() : top(nullptr) {}
  
  Stack(int val) : top(new Node(val)) {}

  void push(int val) {
    Node *t = new Node(val);
    t->next = top;
    top = t;
  }

  int pop() {
    if (isEmpty())
      throw runtime_error("Stack is empty");
    Node *t = top;
    int x = t->data;
    top = top->next;
    delete t;
    return x;
  }

  int getTop() const {
    if (isEmpty())
      throw runtime_error("Stack is empty");
    return top->data;
  }

  bool isEmpty() const {
    return top == nullptr;
  }

  void display() const {
    if (isEmpty()) {
      cout << "Stack is empty" << endl;
      return;
    }
    Node *p = top;
    while (p != nullptr) {
      cout << p->data << " | ";
      p = p->next;
    }
    cout << endl;
  }

  int peek(int index) const {
    if (isEmpty())
      throw runtime_error("Stack is empty");
    Node *t = top;
    for (int i = 0; t != nullptr && i < index - 1; i++)
      t = t->next;
    if (t == nullptr)
      throw runtime_error("Invalid index");
    return t->data;
  }

  ~Stack() {
    while (top != nullptr) {
      Node *temp = top;
      top = top->next;
      delete temp;
    }
  }
};

int main() {
  try {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    cout << "Top element: " << s.getTop() << endl;
    cout << "Peek at index 2: " << s.peek(2) << endl;

    cout << "Popping: " << s.pop() << endl;
    s.display();

    cout << "Popping all elements..." << endl;
    s.pop();
    s.pop();

    // Uncommenting the next line will throw an error
    // s.pop();

    s.display();
  } catch (const exception &e) {
    cerr << e.what() << endl;
  }

  return 0;
}
