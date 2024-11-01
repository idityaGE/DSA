#include <bits/stdc++.h>
using namespace std;

int countsubset(vector<int> &arr, int k, long long s = 0, int ind = 0) {
  if(s > k) return false;
  if (ind == arr.size()) {
    if (s == k)
      return 1;
    return 0;
  }
  s += arr[ind];
  int x = countsubset(arr, k, s, ind + 1);

  s -= arr[ind];
  int y = countsubset(arr, k, s, ind + 1);
  return x + y;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << countsubset(arr, 5);

  return 0;
}