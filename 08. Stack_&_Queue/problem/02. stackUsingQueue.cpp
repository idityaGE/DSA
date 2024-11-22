#include <bits/stdc++.h>
using namespace std;

// Using 1 Queue
class Stack_1 {
  queue<int> que;

 public:
  Stack_1() {}

  void push(int x) {
    que.push(x);
    int n = que.size();

    for (int i = 0; i < n - 1; i++) {
      que.push(que.front());
      que.pop();
    }
  }

  int pop() {
    int n = que.front();
    que.pop();
    return n;
  }

  int top() { return que.front(); }

  bool empty() { return que.empty(); }
};

// Using 2 Queue
class Stack_2 {
  queue<int> q1;
  queue<int> q2;

 public:
  Stack_2() {}

  void push(int x) {
    q2.push(x);
    while (!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    swap(q1, q2);
  }

  int pop() {
    int n = q1.front();
    q1.pop();
    return n;
  }

  int top() { return q1.front(); }

  bool empty() { return q1.empty(); }
};

int main() {
  return 0;
}