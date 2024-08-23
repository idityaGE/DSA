#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[low];
  int i = low, j = high;
  while (i < j) {
    // For decending order
    // `arr[i] <= pivot` --> `arr[i] >= pivot`
    // `arr[j] >= pivot` --> `arr[i] <= pivot`
    while (arr[i] <= pivot && i <= high - 1) i++;
    while (arr[j] >= pivot && j >= low + 1) j--;
    if (i < j) swap(arr[i], arr[j]);
  }
  swap(arr[low], arr[j]);
  return j;
}

void quick_sort(int arr[], int low, int high) {
  if (low < high) {
    int part_idx = partition(arr, low, high);
    quick_sort(arr, low, part_idx - 1);
    quick_sort(arr, part_idx + 1, high);
  }
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  quick_sort(arr, 0, n - 1);

  print(arr, n);
  return 0;
}