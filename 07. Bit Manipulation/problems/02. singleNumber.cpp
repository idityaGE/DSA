#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &arr) {
  int num = 0;
  for (int i = 0; i < arr.size(); i++)
    num = num ^ arr[i];
  return num;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int singleNum = singleElement(arr);
  cout << singleNum;
  return 0;
}