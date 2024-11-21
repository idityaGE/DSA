#include <bits/stdc++.h>
using namespace std;

bool isValid(string str) {
  stack<char> st;
  for (char ch : str) {
    if (ch == '(' || ch == '[' || ch == '{') {
      st.push(ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      if (st.empty()) {
        return false;  // No matching opening bracket
      }
      char top = st.top();
      st.pop();
      if ((top == '(' && ch != ')') ||
          (top == '[' && ch != ']') ||
          (top == '{' && ch != '}')) {
        return false;  // Mismatched bracket
      }
    }
  }
  return st.empty();  // Ensure all brackets are matched
}

int main() {
  return 0;
}