#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void move_0_to_last(int arr[], int n) {
  int j = -1;
  // find where the first zero is
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      j = i;
      break;
    }
  }
  // if no zero then
  if (j == -1)
    return;

  // using two pointer
  for (int i = j + 1; i < n; i++) {
    if (arr[i] != 0) {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  move_0_to_last(arr, n);
  print(arr, n);

  return 0;
}