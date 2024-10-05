#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &arr, int k) {
  int n = arr.size();
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == k)
      return true;
    if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
      low++;
      high--;
    }
    if (arr[low] <= arr[mid]) {
      if (arr[low] <= k && k <= arr[mid])
        high = mid - 1;
      else
        low = mid + 1;
    } else {
      if (arr[mid] <= k && k <= arr[high])
        low = mid + 1;
      else
        high = mid - 1;
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << searchInARotatedSortedArrayII(arr, 2);
  return 0;
}