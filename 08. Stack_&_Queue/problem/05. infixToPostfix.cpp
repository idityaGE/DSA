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
string infixToPosfix(string s) {
  stack<char> st;
  string ans = "";
  for (char ch : s) {
    if (isOperand(ch))
      ans += ch;
    else if (ch == '(')
      st.push(ch);
    else if (ch == ')') {
      while (!st.empty() && st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      if (!st.empty()) st.pop();
    } else {
      while (!st.empty() && priority(ch) <= priority(st.top())) {
        ans += st.top();
        st.pop();
      }
      st.push(ch);
    }
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  string ans = infixToPosfix(s);
  cout << ans;
  return 0;
}

/*
i/p - a+b*(c^d-e)
o/p - abcd^e-*+
*/