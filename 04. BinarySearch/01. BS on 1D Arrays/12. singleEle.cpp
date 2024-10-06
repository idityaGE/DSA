#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr) {
  int n = arr.size();
  if (n == 1) return arr[0];
  if (arr[0] != arr[1]) return arr[0];
  if (arr[n - 1] != arr[n - 2]) return arr[n - 1];
  int low = 0;
  int high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
      return arr[mid];
    else {
      if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||  // left part (even, odd) index
          (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
        low = mid + 1;
      else  // right part (odd, even) index
        high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << singleNonDuplicate(arr);
  return 0;
}