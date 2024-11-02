#include <bits/stdc++.h>
using namespace std;

bool isSubsetPresent(vector<int> &arr, int k, long long s = 0, int ind = 0) {
  // only if arr contains only positive
  if (s > k) return false;

  if (ind == arr.size()) {
    if (s == k)
      return true;
    return false;
  }
  s += arr[ind];
  if (isSubsetPresent(arr, k, s, ind + 1))
    return true;

  s -= arr[ind];
  if (isSubsetPresent(arr, k, s, ind + 1))
    return true;
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << isSubsetPresent(arr, 2);

  return 0;
}