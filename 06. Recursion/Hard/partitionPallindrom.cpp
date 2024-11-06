#include <bits/stdc++.h>
using namespace std;

bool isPallin(string s, int low, int high) {
  while (low < high)
    if (s[low++] != s[high--])
      return 0;
  return 1;
}

void solve(string s, vector<string>& substr, vector<vector<string>>& ans,
           int index = 0) {
  if (index == s.size()) {
    ans.push_back(substr);
    return;
  }

  for (int i = index; i < s.size(); i++) {
    if (isPallin(s, index, i)) {
      substr.push_back(s.substr(index, i - index + 1));
      solve(s, substr, ans, i + 1);
      substr.pop_back();
    }
  }
}

int main() {
  string s;
  cin >> s;
  vector<vector<string>> ans;
  vector<string> substr;
  solve(s, substr, ans);

  for (auto i : ans) {
    for (auto j : i)
      cout << j << "  ";
    cout << endl;
  }

  return 0;
}

/*
Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]

Input: aabb
Output:
a  a  b  b
a  a  bb
aa  b  b
aa  bb
*/