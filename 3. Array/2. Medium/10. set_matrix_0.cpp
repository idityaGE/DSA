#include <iostream>
#include <vector>
using namespace std;

void print(const vector<vector<int>>& mat, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }
}

void set_zero(vector<vector<int>>& mat, int row, int col) {
  vector<int> r(row, 0), c(col, 0);
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (mat[i][j] == 0) r[i] = 1, c[j] = 1;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (r[i] || c[j]) mat[i][j] = 0;
}

void opt_set_zero(vector<vector<int>>& mat, int row, int col) {
  int col_0 = 1;
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      if (mat[i][j] == 0) {
        mat[i][0] = 0;
        if (j != 0)
          mat[0][j] = 0;
        else
          col_0 = 0;
      };

  for (int i = 1; i < row; i++)
    for (int j = 1; j < col; j++)
      if (mat[i][j] != 0) {
        if (mat[i][0] || mat[0][j] == 0) mat[i][j] = 0;
      }
  if (mat[0][0] == 0)
    for (int j = 0; j < col; j++)
      mat[0][j] = 0;

  if (col_0 == 0)
    for (int i = 0; i < row; i++)
      mat[i][0] = 0;
}

int main() {
  int row, col;
  cin >> row >> col;
  vector<vector<int>> mat(row, vector<int>(col));
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      cin >> mat[i][j];
  print(mat, row, col);
  opt_set_zero(mat, row, col);
  cout << "After setting zeroes:" << endl;
  print(mat, row, col);

  return 0;
}
