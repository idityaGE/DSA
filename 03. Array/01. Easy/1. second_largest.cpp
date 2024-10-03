#include <bits/stdc++.h>
using namespace std;

int second_largest(int arr[], int n) {
  int largest = INT_MIN;
  int sec_largest = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
      sec_largest = largest;
      largest = arr[i];
    }
    if (arr[i] > sec_largest && largest > arr[i])
      sec_largest = arr[i];
  }
  if(largest == sec_largest) return -1;
  return sec_largest;
}

int second_smallest(int arr[], int n) {
  int smallest = INT_MAX;
  int sec_smallest = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (arr[i] < smallest) {
      sec_smallest = smallest;
      smallest = arr[i];
    }
    if (arr[i] < sec_smallest && smallest < arr[i])
      sec_smallest = arr[i];
  }
  if(smallest == sec_smallest) return -1;
  return sec_smallest;
}

int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "second_smallest : " << second_smallest(arr, n) << endl;
  cout << "second_largest : " << second_largest(arr, n) << endl;
  return 0;
}