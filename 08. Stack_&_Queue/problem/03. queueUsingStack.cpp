#include <bits/stdc++.h>
using namespace std;

class MyQueue {
 public:
  stack<int> st1;  // Stack to hold elements in the order of insertion
  stack<int> st2;  // Stack for dequeuing elements

  MyQueue() {}

  void push(int x) {
    // Push new elements directly onto st1
    st1.push(x);
  }

  int pop() {
    // Move elements to st2 only if it's empty
    if (st2.empty()) {
      while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
    }
    // Pop the top element from st2
    int n = st2.top();
    st2.pop();
    return n;
  }

  int peek() {
    // Move elements to st2 only if it's empty
    if (st2.empty()) {
      while (!st1.empty()) {
        st2.push(st1.top());
        st1.pop();
      }
    }
    // Return the top element from st2
    return st2.top();
  }

  bool empty() {
    // The queue is empty only if both stacks are empty
    return st1.empty() && st2.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
  return 0;
}