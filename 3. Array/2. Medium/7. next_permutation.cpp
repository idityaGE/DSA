#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr) {
  // next_permutation(arr.begin(), arr.end());

  int n = arr.size();
  int index = -1;
  for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    reverse(arr.begin(), arr.end());
    return;
  }
  for (int i = n - 1; n > index; i--) {
    if (arr[i] > arr[index]) {
      swap(arr[i], arr[index]);
      break;
    }
  }
  reverse(arr.begin() + index + 1, arr.end());
  for (auto i : arr) {
    cout << i << " ";
  }
}
// 3 1 2
// 3 2 1

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  nextPermutation(arr);
  return 0;
}