#include <bits/stdc++.h>
using namespace std;

class Stack {
  int size;
  int top;
  int *s;

 public:
  Stack(int size)
      : size(size), top(-1), s(new int[size]) {}

  void push(int val) {
    if (top == size - 1)
      throw runtime_error("Stack is full");
    s[++top] = val;
  }

  int pop() {
    if (isEmpty())
      throw runtime_error("Stack is empty");
    return s[top--];
  }

  int top() {
    if (isEmpty())
      throw runtime_error("Stack is empty");
    return s[top];
  }

  bool isEmpty() {
    return top == -1;
  }

  int size() {
    return top + 1;
  }

  ~Stack() {
    delete[] s;
  }
};

int main() {
  return 0;
}