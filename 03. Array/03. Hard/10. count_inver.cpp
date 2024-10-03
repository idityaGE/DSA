#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int low, int mid, int high) {
  int cnt = 0;
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right])
      temp.push_back(arr[left++]);
    else
      temp.push_back(arr[right++]), cnt += (mid - left + 1);
  }
  while (left <= mid)
    temp.push_back(arr[left++]);
  while (right <= high)
    temp.push_back(arr[right++]);
  for (int i = low; i <= high; i++)
    arr[i] = temp[i - low];
  return cnt;
}

int merge_sort(vector<int> &arr, int low, int high) {
  static int cnt = 0;
  if (low >= high) return cnt;
  int mid = (low + high) / 2;
  merge_sort(arr, low, mid);
  merge_sort(arr, mid + 1, high);
  cnt += merge(arr, low, mid, high);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int low = 0;
  int high = n - 1;
  int cnt = merge_sort(arr, low, high);
  cout << cnt << endl;
  return 0;
}