#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void rotate_left(int arr[], int n, int k) {
  if (n == 0) return;
  k %= n;
  if (k == 0) return;
  vector<int> v(k);
  for (int i = 0; i < k; i++)
    v[i] = arr[i];
  for (int i = k; i < n; i++)
    arr[i - k] = arr[i];
  for (int i = n - k; i < n; i++)
    arr[i] = v[i - (n - k)];
}

void rotate_right(int arr[], int n, int k) {
  if (n == 0) return;
  k %= n;
  if (k == 0) return;
  vector<int> temp(k);
  for (int i = 0; i < k; i++)
    temp[i] = arr[n - k + i];
  for (int i = n - 1; i >= k; i--)
    arr[i] = arr[i - k];
  for (int i = 0; i < k; i++)
    arr[i] = temp[i];

  // better without using extra space for `vector`
  // reverse(arr.begin(), arr.end());
  // reverse(arr.begin(), arr.begin() + k);
  // reverse(arr.begin() + k, arr.end());
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int k;
  cin >> k;

  // rotate_left(arr, n, k);
  rotate_right(arr, n, k);

  print(arr, n);
  return 0;
}