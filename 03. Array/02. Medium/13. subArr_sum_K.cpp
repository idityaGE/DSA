#include <bits/stdc++.h>
using namespace std;

int findAllSubarraysWithGivenSum(vector<int>& arr, int k) {
  map<int, int> mp;
  mp[0] = 1;
  int preSum = 0;
  int cnt = 0;
  for (int i = 0; i < arr.size(); i++) {
    preSum += arr[i];
    int rem = preSum - k;
    cnt += mp[rem];
    mp[preSum]++;
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  return 0;
}