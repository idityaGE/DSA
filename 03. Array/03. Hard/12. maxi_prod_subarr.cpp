#include <bits/stdc++.h>
using namespace std;

int max_subarr_prod(vector<int> &arr) {
  int n = arr.size();
  if (n == 1) return arr[0];
  int pre = 1;
  int suf = 1;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (pre == 0)
      pre = 1;
    if (suf == 0)
      suf = 1;
    pre *= arr[i];
    suf *= arr[n - i - 1];
    ans = max(ans, max(pre, suf));
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << max_subarr_prod(arr) << endl;
  return 0;
}