#include <bits/stdc++.h>
using namespace std;

int max_1(int arr[], int n) {
  int max1 = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 1) {
      cnt++;
      max1 = max(cnt, max1);
    } else
      cnt = 0;
  }
  return max1;
}


int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "max consecutive one : " << max_1(arr, n);
  return 0;
}