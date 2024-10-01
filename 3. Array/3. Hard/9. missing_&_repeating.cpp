#include <bits/stdc++.h>
using namespace std;

pair<int, int> repeating_and_missing(vector<int> &arr) {
  int n = arr.size();
  vector<int> vc(n + 1);
  for (int i = 0; i < n; i++)
    vc[arr[i]]++;
  pair<int, int> pp;
  for (int i = 0; i <= n; i++) {
    if (vc[i] == 2) pp.first = i;
    if (vc[i] == 0) pp.second = i;
  }
  cout << pp.first << " " << pp.second << endl;
  return pp;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  pair<int, int> pp = repeating_and_missing(arr);
  return 0;
}