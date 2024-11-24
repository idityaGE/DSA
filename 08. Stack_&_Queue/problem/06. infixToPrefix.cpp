#include <bits/stdc++.h>
using namespace std;

bool isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int priority(char ch) {
  switch (ch) {
    case '^':
      return 3;
    case '*':
    case '/':
      return 2;
    case '+':
    case '-':
      return 1;
    default:
      return -1;
  }
}

string infixToPrefix(string s) {
  string ans;
  stack<char> st;
  
  // Reverse the input expression
  reverse(s.begin(), s.end());

  // Replace '(' with ')' and vice versa to handle reversed notation
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      s[i] = ')';
    else if (s[i] == ')')
      s[i] = '(';
  }

  // Convert infix to postfix (in the reversed string)
  for (char ch : s) {
    if (isOperand(ch)) {
      ans += ch;
    } else if (ch == '(') {
      st.push(ch);
    } else if (ch == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      if (!st.empty()) st.pop();
    } else {  // Operator
      while (!st.empty() && priority(ch) < priority(st.top())) {
        ans += st.top();
        st.pop();
      }
      st.push(ch);
    }
  }

  // Pop all remaining operators in the stack
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  // Reverse the result to get the prefix expression
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  string s;
  cin >> s;

  string ans = infixToPrefix(s);
  cout << ans << endl;

  return 0;
}

/*
i/p - (A+B)*C-D+F
o/p - +-*+ABCDF
*/