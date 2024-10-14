#include <bits/stdc++.h>
using namespace std;

pair<int, int> searchMatrix(vector<vector<int>>& matrix, int target) {
  int n = matrix.size();
  int m = matrix[0].size();
  int row = 0, col = m - 1;
  while (row < n && col >= 0) {
    if (matrix[row][col] == target)
      return {row, col};
    else if (matrix[row][col] < target)
      row++;
    else
      col--;
  }
  return {-1, -1};
}

int main() {
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  pair<int, int> pp = searchMatrix(matrix, 11);
  cout << pp.first << "  " << pp.second;
  return 0;
}