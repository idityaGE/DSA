#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

vector<int> union_sorted(int arr1[], int arr2[], int n, int m) {
  // brute force approach
  // vector<int> v;
  // set<int> st;
  // for (int i = 0; i < max(m, n); i++) {
  //   if (i < n) st.insert(arr1[i]);
  //   if (i < m) st.insert(arr2[i]);
  // }
  // for (auto it : st) {
  //   v.push_back(it);
  // }
  // return v;

  // Using two pointer
  vector<int> v;
  int i = 0, j = 0;
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) {
      if (v.size() == 0 || v.back() != arr1[i])
        v.push_back(arr1[i]);
      i++;
    } else {
      if (v.size() == 0 || v.back() != arr2[j])
        v.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) {
    if (v.size() == 0 || v.back() != arr1[i])
      v.push_back(arr1[i]);
    i++;
  }
  while (j < m) {
    if (v.size() == 0 || v.back() != arr2[j])
      v.push_back(arr2[j]);
    j++;
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

  v = union_sorted(arr1, arr2, n, m);

  for (auto it : v)
    cout << it << " ";

  return 0;
}