#include <bits/stdc++.h>
using namespace std;

int subarr_xor_k(vector<int> &arr, int k) {
  // formula =>  x = xr ^ k
  int xr = 0;
  map<int, int> mpp;
  mpp[xr]++;  // {0 , 1}
  int cnt = 0;
  for (int i = 0; i < arr.size(); i++) {
    xr = xr ^ arr[i];
    int x = xr ^ k;
    cnt += mpp[x];  // return 0 if not present
    mpp[xr]++;
  }
  return cnt;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << subarr_xor_k(arr, 6) << endl;
  return 0;
}