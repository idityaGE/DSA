#include <bits/stdc++.h>
using namespace std;

int pivot_index(vector<int>& arr) {
  int n = arr.size();
  int low = 0, high = n - 1;
  int ans = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[0] <= arr[mid])
      low = mid + 1;
    else {
      ans = mid;
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

  cout << pivot_index(arr);
  return 0;
}