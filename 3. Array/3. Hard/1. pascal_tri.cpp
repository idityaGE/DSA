#include <bits/stdc++.h>
using namespace std;

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
  return 0;
}