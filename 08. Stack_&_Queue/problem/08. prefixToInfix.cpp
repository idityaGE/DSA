#include <bits/stdc++.h>
using namespace std;

bool isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string PrefixToInfix(string s) {
  stack<string> st;

  // Iterate from the end of the string to the beginning
  for (int i = s.length() - 1; i >= 0; i--) { 
    char ch = s[i];
    if (isOperand(ch)) {
      st.push(string(1, ch));
    } else {
      // Ensure there are at least two operands on the stack
      if (st.size() < 2) {
        return "Error: Invalid prefix expression";
      }

      // Pop two operands
      string t1 = st.top(); st.pop();
      string t2 = st.top(); st.pop();
      
      // Form the infix expression with the operator between the operands
      string str = '(' + t1 + ch + t2 + ')';
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
  cout << "Enter prefix expression: ";
  cin >> s;

  string result = PrefixToInfix(s);
  cout << result << endl;

  return 0;
}

/*
i/p - +-*+ABCDF
o/p - ((((A+B)*C)-D)+F)
*/