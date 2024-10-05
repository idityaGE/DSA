#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;  // overflow handle
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int binarySearchRecursion(vector<int> &arr, int low, int high, int target) {
  if (low > high) return -1;
  int mid = low + (high - low) / 2;
  if (arr[mid] == target)
    return mid;
  else if (arr[mid] < target)
    return binarySearchRecursion(arr, mid + 1, high, target);
  else
    return binarySearchRecursion(arr, low, mid - 1, target);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << binarySearch(arr, 7) << endl;
  cout << binarySearchRecursion(arr, 0, n - 1, 10);
  return 0;
}
