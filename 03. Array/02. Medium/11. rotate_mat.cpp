#include <bits/stdc++.h>
using namespace std;

void print(const vector<vector<int>>& mat, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }
}

void rotate_matrix(vector<vector<int>>& mat) {
  int n = mat.size();
  // Transpose 
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      swap(mat[i][j], mat[j][i]);
  // reverse every row
  for (int i = 0; i < n; i++)
    reverse(mat[i].begin(), mat[i].end());
}

int main() {
  int row, col;
  cin >> row >> col;
  vector<vector<int>> mat(row, vector<int>(col));
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      cin >> mat[i][j];

  rotate_matrix(mat);
  print(mat, row, col);
  return 0;
}