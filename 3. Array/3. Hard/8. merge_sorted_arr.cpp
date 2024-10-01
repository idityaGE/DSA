#include <bits/stdc++.h>
using namespace std;

// Brute
void merge_sorted_arr_without_extra_space(vector<int>& arr1, vector<int>& arr2) {
  int n = arr1.size();
  int m = arr2.size();
  vector<long long> c(n + m);
  int left = 0;
  int right = 0;
  int index = 0;
  while (left < n && right < m) {
    if (arr1[left] <= arr2[right])
      c[index++] = arr1[left++];
    else
      c[index++] = arr2[right++];
  }
  while (left < n)
    c[index++] = arr1[left++];
  while (right < m)
    c[index++] = arr2[right++];

  for (int i = 0; i < n + m; i++) {
    if (i < n)
      arr1[i] = c[i];
    else
      arr2[i - n] = c[i];
  }
  for (auto i : arr1)
    cout << i << " ";
  cout << endl;
  for (auto i : arr2)
    cout << i << " ";
}

// better
void merge_sorted_arr_without_extra_space_1(vector<int>& arr1, vector<int>& arr2) {
  int n = arr1.size();
  int m = arr2.size();
  int left = n - 1;
  int right = 0;
  while (left >= 0 && right < m) {
    if (arr1[left] > arr2[right])
      swap(arr1[left--], arr2[right++]);
    else
      // because they are sorted already
      break;
  }
  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());
  for (auto i : arr1)
    cout << i << " ";
  cout << endl;
  for (auto i : arr2)
    cout << i << " ";
}

void swapifgreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2) {
  if (arr1[ind1] > arr2[ind2])
    swap(arr1[ind1], arr2[ind2]);
}

// optimal [gap method] from [sell sort]
void merge_sorted_arr_without_extra_space_2(vector<int>& arr1, vector<int>& arr2) {
  int n = arr1.size();
  int m = arr2.size();
  int len = n + m;
  int gap = (len / 2) + (len % 2);  // or you can use ceil fun
  while (gap > 0) {
    int left = 0;
    int right = gap;
    while (right < len) {
      if (left < n && right >= n)
        swapifgreater(arr1, arr2, left, right - n);
      else if (left >= n)
        swapifgreater(arr2, arr2, left - n, right - n);
      else
        swapifgreater(arr1, arr1, left, right);
      left++, right++;
    }
    if (gap == 1)
      break;
    else
      gap = (gap / 2) + (gap % 2);
  }
  for (auto i : arr1)
    cout << i << " ";
  cout << endl;
  for (auto i : arr2)
    cout << i << " ";
}
/* input
4
1 3 5 7
5
0 2 6 8 9
*/

// leetcode problem 88
void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
  // First copy arr2 into arr1 from index m onward
  for (int i = 0; i < m; i++) {
    arr1[n + i] = arr2[i];
  }
  int len = m + n;
  int gap = (len / 2) + (len % 2);
  while (gap > 0) {
    int left = 0;
    int right = gap;
    while (right < len) {
      // Handle cases where both indices are within arr1 (after combining)
      if (right < len) {
        swapifgreater(arr1, arr1, left, right);
      }
      left++;
      right++;
    }
    if (gap == 1)
      break;
    else
      gap = (gap / 2) + (gap % 2);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr1(n);
  for (int i = 0; i < n; i++)
    cin >> arr1[i];

  int m;
  cin >> m;
  vector<int> arr2(m);
  for (int i = 0; i < m; i++)
    cin >> arr2[i];

  merge_sorted_arr_without_extra_space_2(arr1, arr2);

  return 0;
}