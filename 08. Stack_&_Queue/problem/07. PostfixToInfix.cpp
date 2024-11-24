#include <bits/stdc++.h>
using namespace std;

bool isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string PostfixToInfix(string s) {
  stack<string> st;

  for (char ch : s) {
    if (isOperand(ch)) {
      // Push operand as a string onto the stack
      st.push(string(1, ch));
    } else {
      // Ensure there are at least two operands to pop
      if (st.size() < 2) {
        return "Error: Invalid postfix expression";
      }
      
      string t1 = st.top(); st.pop();
      string t2 = st.top(); st.pop();
      string str = '(' + t2 + ch + t1 + ')';
      st.push(str);
    }
  }

  // Check if there's exactly one result in the stack
  if (st.size() != 1) {
    return "Error: Invalid postfix expression";
  }

  return st.top();
}

int main() {
  string s;
  cin >> s;

  string result = PostfixToInfix(s);
  cout << result << endl;

  return 0;
}


/*
i/p - abcd^e-*+
o/p - (a+(b*((c^d)-e)))
*/