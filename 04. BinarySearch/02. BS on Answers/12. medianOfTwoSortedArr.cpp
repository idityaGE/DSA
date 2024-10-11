#include <bits/stdc++.h>
using namespace std;

// brute
double median_brute(vector<int>& arr1, vector<int>& arr2) {
  int n = arr1.size();
  int m = arr2.size();
  int totalSize = (n + m);
  vector<int> mergeArr(totalSize);
  int i = 0, j = 0, k = 0;
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j])
      mergeArr[k++] = arr1[i++];
    else
      mergeArr[k++] = arr2[j++];
  }
  while (i < n)
    mergeArr[k++] = arr1[i++];
  while (j < m)
    mergeArr[k++] = arr2[j++];
  return (totalSize % 2 == 1) ? (double)mergeArr[totalSize / 2]
                              : (mergeArr[totalSize / 2 - 1] + mergeArr[totalSize / 2]) / 2.0;
}

// Better
double median_better(vector<int>& a, vector<int>& b) {
  int n1 = a.size(), n2 = b.size(), n = n1 + n2;
  int ind1 = (n - 1) / 2, ind2 = n / 2;
  int i = 0, j = 0, cnt = 0, val1 = 0, val2 = 0;
  while (i < n1 || j < n2) {
    int val = (i < n1 && (j >= n2 || a[i] < b[j])) ? a[i++] : b[j++];
    if (cnt == ind1) val1 = val;
    if (cnt == ind2) val2 = val;
    cnt++;
  }
  return (n % 2 == 1) ? val2 : (val1 + val2) / 2.0;
}

// optimal
double median(vector<int>& a, vector<int>& b) {
  int n1 = a.size();
  int n2 = b.size();
  if (n1 > n2) return median(b, a);
  int left = (n1 + n2 + 1) / 2;
  int n = n1 + n2;
  int low = 0, high = n1;
  while (low <= high) {
    int mid1 = low + (high - low) / 2;
    int mid2 = left - mid1;
    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;
    if (mid1 < n1) r1 = a[mid1];
    if (mid2 < n2) r2 = b[mid2];
    if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
    if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
    if (l1 <= r2 && l2 <= r1) {
      if (n % 2 == 1) return max(l1, l2);
      return (double)((max(l1, l2) + min(r1, r2))) / 2.0;
    } else if (l1 > l2)
      high = mid1 - 1;
    else
      low = mid1 + 1;
  }
  return 0;
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

  cout << median(arr1, arr2);
  return 0;
}

/*
Sample Input 1:
3 3
2 4 6
1 3 5
Sample Output 1:
3.5
Explanation of Sample Input 1 :
The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }.
Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.
*/