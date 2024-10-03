#include <bits/stdc++.h>
using namespace std;

void print(const vector<vector<int>>& mat, int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++)
      cout << mat[i][j] << " ";
    cout << endl;
  }
}

void spiral_traverse(vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();
  int left = 0, right = m - 1;
  int top = 0, bottom = n - 1;
  vector<int> ans;
  while (left <= right && top <= bottom) {
    // top
    for (int i = left; i <= right; i++)
      ans.push_back(mat[top][i]);
    top++;
    // right
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][right]);
    right--;
    // bottom
    if (top <= bottom) {
      for (int i = right; i >= left; i--)
        ans.push_back(mat[bottom][i]);
      bottom--;
    }
    // left
    if (left <= right) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][left]);
      left++;
    }
  }

  for (auto i : ans)
    cout << i << " ";
}

int main() {
  int row, col;
  cin >> row >> col;
  vector<vector<int>> mat(row, vector<int>(col));
  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      cin >> mat[i][j];

  spiral_traverse(mat);
  return 0;
}