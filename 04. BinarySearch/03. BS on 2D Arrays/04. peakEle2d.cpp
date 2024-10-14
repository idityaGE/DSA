#include <bits/stdc++.h>
using namespace std;

int findMaxInColumn(const vector<vector<int>> &mat, int n, int col) {
  int index = 0;  // Initialize to the first row
  for (int i = 1; i < n; i++) {
    if (mat[i][col] > mat[index][col]) {
      index = i;
    }
  }
  return index;
}

pair<int, int> findPeakGrid(vector<vector<int>> &g) {
  int n = g.size();
  int m = g[0].size();
  int low = 0, high = m - 1;
  
  while (low <= high) {
    int mid = low + (high - low) / 2;
    int maxRow = findMaxInColumn(g, n, mid);
    int left = (mid - 1 >= 0) ? g[maxRow][mid - 1] : -1;
    int right = (mid + 1 < m) ? g[maxRow][mid + 1] : -1;
    if (g[maxRow][mid] > left && g[maxRow][mid] > right)
      return {maxRow, mid};
    else if (left > g[maxRow][mid])
      high = mid - 1;
    else
      low = mid + 1;
  }
  return {-1, -1};
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  pair<int, int> pp = findPeakGrid(matrix);
  cout << pp.first << "  " << pp.second;
  return 0;
}