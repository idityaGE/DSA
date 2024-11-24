#include <bits/stdc++.h>
using namespace std;

bool isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string prefixToPostfix(string s) {
  stack<string> st;

  for (int i = s.length() - 1; i >= 0; i--) {
    char ch = s[i];

    if (isOperand(ch)) {
      st.push(string(1, ch));
    } else {
      if (st.size() < 2) {
        return "Error: Invalid prefix expression";
      }

      // Pop two operands
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();

      // Form the postfix expression and push it back to the stack
      string str = t1 + t2 + ch;
      st.push(str);
    }
  }

  // At the end, there should be exactly one element in the stack
  if (st.size() != 1) {
    return "Error: Invalid prefix expression";
  }

  return st.top();
}

int main() {
  string s;
  cin >> s;

  string result = prefixToPostfix(s);
  cout << result << endl;

  return 0;
}

// i/p - /-AB*+DEF
// o/p - AB-DE+F*/
