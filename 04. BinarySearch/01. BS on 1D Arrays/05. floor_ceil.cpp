#include <bits/stdc++.h>
using namespace std;

/*
Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
*/

int floor(vector<int> &arr, int x) {
  int low = 0;
  int high = arr.size() - 1;
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] <= x) {
      ans = arr[mid];
      low = mid + 1;
    } else
      high = mid - 1;
  }
  return ans;
}

int ciel(vector<int> &arr, int x) {
  int low = 0;
  int high = arr.size() - 1;
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= x) {
      ans = arr[mid];
      high = mid + 1;
    } else
      low = mid + 1;
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << floor(arr, 5);
  cout << ciel(arr, 5);
  return 0;
}