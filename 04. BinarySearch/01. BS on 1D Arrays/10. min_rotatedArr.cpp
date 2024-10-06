#include <bits/stdc++.h>
using namespace std;

int mini_or_pivot(vector<int>& arr) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = INT_MAX;
  while (low <= high) {
    int mid = (low + high) / 2;
    // more optimization
    if (arr[low] <= arr[high]) { // if all are sorted
      ans = min(ans, arr[low]);
      break;
    }
    if (arr[low] <= arr[mid]) { // left part sorted
      ans = min(ans, arr[low]);
      low = mid + 1;
    } else {                   // right part sorted
      ans = min(ans, arr[mid]);
      high = mid - 1;
    }
  }
  return ans;
}

// method 2
int findMin(vector<int>& arr) {
  int low = 0, high = arr.size() - 1;
  int ans = arr[0];
  while (low <= high) {
    int mid = high + (low - high) / 2;
    if (arr[0] <= arr[mid])   // if low to mid is sorted then arr[0] will pe minimun and go right to find min
      low = mid + 1;
    else {                    // if mid to high is sorted the arr[mid] will be minimun and go left to find min
      ans = arr[mid];
      high = mid - 1;
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << mini_or_pivot(arr);

  cout << endl
       << findMin(arr);
  return 0;
}