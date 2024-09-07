#include <bits/stdc++.h>
using namespace std;

void leader(vector<int> &arr) {
  int n = arr.size();
  int maxi = INT_MIN;
  vector<int> ans;
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] > maxi) {
      ans.push_back(arr[i]);
    }
    maxi = max(maxi, arr[i]);
  }
  reverse(ans.begin(), ans.end());
  for (auto i : ans) {
    cout << i << " ";
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  leader(arr);
  return 0;
}