#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

vector<int> intersection_sorted(int arr1[], int arr2[], int n, int m) {
  vector<int> v;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (arr1[i] < arr2[j]) {
      i++;
    } else if (arr2[j] > arr1[i]) {
      j++;
    } else {
      v.push_back(arr1[i]);
      i++;
      j++;
    }
  }
  return v;
}

int main() {
  int n;
  int m;
  cin >> n >> m;
  int arr1[n];
  int arr2[m];
  for (int i = 0; i < n; i++)
    cin >> arr1[i];
  for (int i = 0; i < m; i++)
    cin >> arr2[i];

  vector<int> v;

  v = intersection_sorted(arr1, arr2, n, m);

  for (auto it : v)
    cout << it << " ";

  return 0;
}