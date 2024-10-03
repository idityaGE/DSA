#include <bits/stdc++.h>
using namespace std;

int missing_ele(int arr[], int n, int N) {
  // better force
  // vector<int> hash(N + 1);
  // for (int i = 0; i < n; i++)
  //   hash[arr[i]]++;
  // for (int i = 1; i < N + 1; i++)
  //   if (hash[i] == 0) return N;
  // return -1;

  // optimised
  // int sum = (N * (N + 1)) / 2;
  // int sumArr = 0;
  // for (int i = 0; i < n; i++) {
  //   sumArr += arr[i];
  // }
  // return sum - sumArr;

  // more optimised using XOR
  // why this is better because unline sum variable it doesn't calcu and store a large value which can overflow
  int XOR1 = 0, XOR2 = 0;
  for (int i = 0; i < n; i++) {
    XOR1 = XOR1 ^ (i + 1);
    XOR2 = XOR2 ^ arr[i];
  }
  XOR1 = XOR1 ^ N;
  return XOR1 ^ XOR2;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Missing ele : " << missing_ele(arr, n, 7);

  return 0;
}