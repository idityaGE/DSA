#include <bits/stdc++.h>
using namespace std;

int Longest_subarray_positive_only(int arr[], int n, int k) {
  int left = 0;
  int right = 0;
  int maxLen = 0;
  int sum = arr[0];
  while (right < n) {
    while (left <= right && sum > k) {
      sum -= arr[left];
      left++;
    }
    if (sum == k) maxLen = max(maxLen, right - left + 1);
    right++;
    if (right < n) sum += arr[right];
  }
  return maxLen;
}

int Longest_subarray(int arr[], int n, int k) {
  map<int, int> mp;
  int sum = 0;
  int maxLen = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
    if (sum == k) maxLen = max(maxLen, i + 1);
    int rem = sum - k;
    if (mp.find(rem) != mp.end()) {
      int len = i - mp[rem];
      maxLen = max(maxLen, len);
    }
    if(mp.find(sum) == mp.end()) mp[sum] = i;
  }
  return maxLen;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int k;
  cin >> k;

  cout << Longest_subarray(arr, n, k);

  return 0;
}