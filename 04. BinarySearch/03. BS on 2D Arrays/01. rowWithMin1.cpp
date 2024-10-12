

#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high) {
    int mid = (low + high) / 2;
    // maybe an answer
    if (arr[mid] >= x) {
      ans = mid;
      // look for smaller index on the left
      high = mid - 1;
    } else {
      low = mid + 1;  // look on the right
    }
  }
  return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
  int cnt_max = 0;
  int index = -1;

  // traverse the rows:
  for (int i = 0; i < n; i++) {
    // get the number of 1's:
    int cnt_ones = m - lowerBound(matrix[i], m, 1);
    if (cnt_ones > cnt_max) {
      cnt_max = cnt_ones;
      index = i;
    }
  }
  return index;
}

int main() {
  vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
  int n = 3, m = 3;
  cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
}

/*
Sample Input 1:
3 3
1 1 1
0 0 1
0 0 0
Sample Output 1:
0
Explanation of the Sample Input 1:
The row with the maximum number of ones is 0 (0 - indexed).
Sample Input 2:
2 2
1 1
1 1
Sample Output 2:
0
Explanation of the Sample Input 2:
Both rows have the same number of ones. Therefore, we will pick the row with smaller index.
*/