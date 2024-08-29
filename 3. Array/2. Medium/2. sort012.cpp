#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

// brute force
void sort_0_1_2(vector<int> &arr, int n) {
  int cnt1 = 0, cnt2 = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) cnt++;
    if (arr[i] == 1) cnt1++;
    if (arr[i] == 2) cnt2++;
  }
  for (int i = 0; i < cnt; i++) arr[i] = 0;
  for (int i = cnt; i < cnt1 + cnt; i++) arr[i] = 1;
  for (int i = cnt + cnt1; i < n; i++) arr[i] = 2;
}

// three pointer [ Dutch national flag algorithm ]
void sort012(vector<int> &arr, int n) {
  int mid = 0, low = 0, high = n - 1;
  while (mid <= high) {
    if (arr[mid] == 0) {
      swap(arr[mid], arr[low]);
      mid++, low++;
    } else if (arr[mid] == 2) {
      swap(arr[mid], arr[high]);
      high--;
    } else
      mid++;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort012(arr, n);
  print(arr, n);

  return 0;
}