#include <bits/stdc++.h>

#include <string>
using namespace std;

int main() {
  string st;
  cin >> st;

  // precomputation
  // imagine all charc are lower case
  int hash[26] = {0};
  for (int i = 0; i < st.size(); i++) {
    hash[st[i] - 'a']++;
  }

  // imagine if it contains all charc
  int hashAll[256] = {0};
  for (int i = 0; i < st.size(); i++) {
    hashAll[st[i]]++;
  }

  int q;
  cin >> q;
  while (q--) {
    char ch;
    cin >> ch;
    // fetch
    // cout << hash[ch - 'a'] << endl;
    cout << hashAll[ch] << endl;
  }

  return 0;
}