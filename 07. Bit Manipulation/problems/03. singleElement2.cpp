#include <bits/stdc++.h>
using namespace std;

// Brute
int singleEle_brute(vector<int> &arr) {
}

// Better O(n log n) + O(n/3)
int singleEle(vector<int> &arr) {
  sort(arr.begin(), arr.end());
  for (int i = 1; i < arr.size(); i += 3)
    if (arr[i] != arr[i - 1]) return arr[i - 1];
  return arr[arr.size() - 1];
}

// optimal
int singleEle_o(vector<int> &arr) {
  int ones = 0;
  int twos = 0;
  for (int i = 0; i < arr.size(); i++) {
    ones = (arr[i] ^ ones) & (~twos);
    twos = (arr[i] ^ twos) & (~ones);
  }
  return ones;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << singleEle_o(arr);
  return 0;
}