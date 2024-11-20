#include <bits/stdc++.h>
using namespace std;

class Node {
  int data;
  int *next;

 public:
  Node(int val)
      : data(val), next(nullptr) {}
};

class Stack {
  Node *top;

 public:
  Stack()
      : top(nullptr) {}
  Stack(int val)
      : top(new Node(val)) {}

  ~Stack() {
    delete top;
  }


  
};

int main() {
  return 0;
}