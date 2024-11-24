#include <bits/stdc++.h>
using namespace std;

class MinStack {
  stack<pair<int, int>> st;

 public:
  MinStack() {}

  void push(int val) {
    if (st.empty())
      st.push({val, val});
    else
      st.push({val, min(val, st.top().second)});
  }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};

// better
class minStack {
  stack<long long> st;
  long long min;

 public:
  minStack()
      : min(INT32_MAX) {}

  void push(int val) {
    if (st.empty()) {
      st.push(val);
      min = val;
    } else {
      if (val < min) {
        st.push((long long)2 * val - min);
        min = val;
      } else
        st.push(val);
    }
  }

  void pop() {
    if (st.empty()) return;
    long long x = st.top();
    st.pop();
    if (x < min)
      min = 2 * min - x;
  }

  int top() {
    if (st.empty())
      return -1;
    long long x = st.top();
    return (x < min) ? min : x;
  }

  int getMin() {
    return min;
  }
};

int main() {
  return 0;
}