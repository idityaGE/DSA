#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
  long long ans = 1;
  for (int i = 0; i < r; i++) {
    ans *= (n - i);
    ans /= (i + 1);
  }
  return ans;
}

vector<int> generRow(int row) {
  long long ans = 1;
  vector<int> ansRow;
  ansRow.push_back(1);
  for (int col = 1; col < row; col++) {
    ans = ans * (row - col);
    ans = ans / (col);
    ansRow.push_back(ans);
  }
  return ansRow;
}

vector<vector<int>> pascalTriangle(int N) {
  vector<vector<int>> ans;
  for (int i = 1; i <= N; i++) {
    ans.push_back(generRow(i));
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> arr;

  arr = pascalTriangle(n);
  for (auto i : arr) {
    for (auto it : i)
      cout << it << " ";
    cout << endl;
  }
  /*
          1
         1 1
        1 2 1
       1 3 3 1
      1 4 6 4 1
    1 5 10 10 5 1

    row = 6, col = 3, ele = 10
    nCr --> n = row - 1 = 5, r = col - 1 = 2 ==> ele = 10;
  */

  cout << nCr(5, 2);
  return 0;
}