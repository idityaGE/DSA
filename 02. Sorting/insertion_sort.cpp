#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Insertion Sort
void insertion_sort(int arr[], int n) {
  for (int i = 1; i < n; i++)
    for (int j = i; j > 0; j--)
      if (arr[j] < arr[j - 1]) swap(arr[j], arr[j - 1]);
      else break;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  insertion_sort(arr, n);

  cout << "After Sort : " << endl;
  print(arr, n);

  return 0;
}