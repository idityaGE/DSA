#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastOccur(vector<int> &arr, int x) {
  int temp = -1;
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
      temp = mid;
      break;
    } else if (x > arr[mid])
      low = mid + 1;
    else
      high = mid - 1;
  }
  if (temp == -1) return {-1, -1};
  int first, last;
  low = high = temp;
  while (arr[low] == x && low >= 0) {
    first = low--;
  }
  while (arr[high] == x && high <= arr.size() - 1) {
    last = high++;
  }
  return {first, last};
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  pair<int, int> occ = firstAndLastOccur(arr, 2);
  cout << occ.first << "  " << occ.second;
  return 0;
}