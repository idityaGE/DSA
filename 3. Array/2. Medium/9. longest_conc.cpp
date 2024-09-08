#include <bits/stdc++.h>
using namespace std;

int longest_consecutive(vector<int> &arr) {
  sort(arr.begin(), arr.end());
  int len = 1;
  int last_small = arr[0];
  int maxLen = 1;
  for (int i = 1; i < arr.size(); i++) {
    if (arr[i] == last_small + 1) {
      len++;
      last_small++;
    } else if (arr[i] == last_small) {
      continue;
    } else {
      len = 1;
      last_small = arr[i];
    }
    maxLen = max(len, maxLen);
  }
  return maxLen;
}

int max_concu(vector<int> &arr) {
  int n = arr.size();
  if (n == 0) return 0;
  int maxLen = 1;
  unordered_set<int> st;
  for (int i = 0; i < n; i++)
    st.insert(arr[i]);
  for (auto i : st) {
    if (st.find(i - 1) == st.end()) {
      int cnt = 1;
      int x = i;
      while (st.find(x + 1) != st.end()) {
        cnt++;
        x++;
      }
      maxLen = max(maxLen, cnt);
    }
  }
  return maxLen;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << max_concu(arr) << endl;
  return 0;
}