#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
  if (num.length() == k) {
    return "0";
  }

  stack<char> st;

  for (char c : num) {
    while (!st.empty() && st.top() > c && k > 0) {
      st.pop();
      k--;
    }
    st.push(c);
  }

  while (k > 0 && !st.empty()) {
    st.pop();
    k--;
  }

  string ans;
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());

  // Remove leading zeros
  while (!ans.empty() && ans[0] == '0') {
    ans.erase(ans.begin());
  }

  // If the result is empty, return "0"
  return ans.empty() ? "0" : ans;
}

int main() {
  return 0;
}

/*
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/