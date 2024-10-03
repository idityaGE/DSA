#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Hashing
  // size of hashing arr depend on what is the largest element in the arr
  int hash[13] = {0};
  for (int i = 0; i < n; i++) {
    hash[arr[i]] += 1;
  }

  int q;
  cin >> q;
  while (q--) {
    int num;
    cin >> num; 
    cout << hash[num] << endl;
  }

  return 0;
}