#include <bits/stdc++.h>
using namespace std;

bool isOperand(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string postfixToPrefix(string s) {
  stack<string> st;
  for (char ch : s) {
    if (isOperand(ch))
      st.push(string(1, ch));
    else {
      if (st.size() < 2) {
        return "Error: Invalid postfix expression";
      }
      string t1 = st.top();
      st.pop();
      string t2 = st.top();
      st.pop();
      string str = ch + t2 + t1;
      st.push(str);
    }
  }
  if (st.size() != 1) {
    return "Error: Invalid postfix expression";
  }
  return st.top();
}

int main() {
  string s;
  cin >> s;

  string result = postfixToPrefix(s);
  cout << result << endl;
  return 0;
}



// i/p - AB-DE+F*/
// o/p - /-AB*+DEF