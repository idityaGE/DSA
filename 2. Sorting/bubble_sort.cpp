#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Bubble Sort
void bubble_sort(int arr[], int n) {
  for (int i = n - 2; i >= 0; i--)
    for (int j = 0; j <= i; j++)
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

// optimised for best case when already sorted
void bubble_sort_optimised(int arr[], int n) {
  for (int i = n - 2; i >= 0; i--) {
    bool isSwapped = false;
    for (int j = 0; j <= i; j++)
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        isSwapped = true;
      }
    if (!isSwapped) break;
    // cout << "loop : " << i << endl;
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  bubble_sort_optimised(arr, n);

  cout << "After Sort : " << endl;
  print(arr, n);

  return 0;
}