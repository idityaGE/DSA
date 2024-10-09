#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int m, int maxPagesPerStudent) {
  int pages = arr[0];
  int students = 1;
  for (int i = 1; i < arr.size(); i++) {
    pages += arr[i];
    if (pages > maxPagesPerStudent) {
      students++;
      pages = arr[i];
    }
  }
  return students <= m;
}

int findPages(vector<int> &arr, int m) {
  int n = arr.size();
  if (m > n)
    return -1;
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (isPossible(arr, m, mid))
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << findPages(arr, 2);
  return 0;
}

/*
Sample Input 1:
4 2
12 34 67 90
Sample Output 1:
113
Explanation of sample input 1:
All possible ways to allocate the ‘4’ books to '2' students are:

12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.

12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.

12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.

We are getting the minimum in the last case.

Hence answer is ‘113’.
*/