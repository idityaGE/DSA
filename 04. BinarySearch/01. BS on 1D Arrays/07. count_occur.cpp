#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &arr, int n, int k) {
  int low = 0, high = n - 1, mid = 0;
  int temp = -1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == k) {
      temp = mid;
      high = mid - 1;
    } else if (k > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return temp;
}
int lastOccurence(vector<int> &arr, int n, int k) {
  int low = 0, high = n - 1, mid = 0;
  int temp = -1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (arr[mid] == k) {
      temp = mid;
      low = mid + 1;
    } else if (k > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  return temp;
}
int count(vector<int> &arr, int n, int x) {
  int firstindex = firstOccurence(arr, n, x);
  int lastindex = lastOccurence(arr, n, x);
  if (firstindex == -1 && lastindex == -1)
    return 0;
  int ans = (lastindex - firstindex) + 1;
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int occ = count(arr, n, 2);
  cout << occ;
  return 0;
}