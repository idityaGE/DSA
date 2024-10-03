#include <bits/stdc++.h>
using namespace std;

vector<int> max_sum_subarr(vector<int> &arr) {
  int maxVal = INT_MIN;
  int sum = 0;
  int st = 0, end = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (sum == 0) st = i;
    sum += arr[i];
    if (sum > maxVal) {
      maxVal = sum;
    }
    end = i;
    if (sum < 0) {
      sum = 0;
    }
  }
  return {st, end, maxVal};
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> ans = max_sum_subarr(arr);
  for (int i : ans) cout << i << " ";
  return 0;
}