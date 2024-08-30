#include <bits/stdc++.h>
using namespace std;

// Leetcode - 169. Majority Element

// Input: nums = [3,2,3]
// Output: 3 --> freq > n/2

int mazority_ele(vector<int> &arr) {
  int n = arr.size();
  // hashing method
  // map<int, int> mp;
  // for (int i = 0; i < n; i++)
  //   mp[arr[i]]++;
  // for (auto it : mp)
  //   if (it.second > n / 2) return it.first;
  // return -1;

  // Moore's voting algo
  int cnt = 1;
  int ele = arr[0];
  for (int i = 1; i < n; i++) {
    if(arr[i] == ele) cnt++;
    else cnt--;
    if(cnt == 0) ele = arr[i+1], cnt = 1, i++;
  }
  return ele;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << mazority_ele(arr) << endl;
  return 0;
}