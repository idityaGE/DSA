#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  unordered_map<int, int> hashmap;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    hashmap[arr[i]]++;
  }

  // display hash map
  for (auto it : hashmap) cout << it.first << " - " << it.second << endl;

  // query
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    // fetch
    cout << hashmap[n] << endl;
  }

  return 0;
}