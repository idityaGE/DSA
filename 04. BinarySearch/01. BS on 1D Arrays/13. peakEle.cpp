#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr) {
  int n = arr.size();
  if (n == 1)
    return 0;
  if (arr[0] > arr[1])
    return 0;
  if (arr[n - 1] > arr[n - 2])
    return n - 1;
  int low = 1;
  int high = n - 2;
  while (low <= high) {
    int mid = high + (low - high) / 2;
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
      return mid;
    else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << findPeakElement(arr);
  return 0;
}