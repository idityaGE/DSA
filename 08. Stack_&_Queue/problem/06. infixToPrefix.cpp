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
      return 2;
    case '/':
      return 2;
    case '+':
      return 1;
    case '-':
      return 1;
    default:
      return -1;
  }
}

string infixToPrefix(string s) {
  string ans = "";
  stack<char> st;
  reverse(s.begin(), s.end());

  // Replace '(' with ')' and vice versa
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      s[i] = ')';
    else if (s[i] == ')')
      s[i] = '(';
  }

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
      st.pop();
    } else {
      if (ch == '^') {
        while (!st.empty() && priority(ch) <= priority(st.top())) {
          ans += st.top();
          st.pop();
        }
      } else {
        while (!st.empty() && priority(ch) < priority(st.top())) {
          ans += st.top();
          st.top();
        }
      }
      st.push(ch);
    }
  }

  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }

  reverse(s.begin(), s.end());
  return ans;
}

int main() {
  string s;
  cin >> s;
  string ans = infixToPrefix(s);
  cout << ans;
  return 0;
}

/*
i/p - (A+B)*C-D+F
o/p - FDCBA+*-+
*/