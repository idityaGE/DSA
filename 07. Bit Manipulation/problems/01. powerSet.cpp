#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& arr) {
  int n = arr.size();
  vector<vector<int>> res;
  int numSubsets = 1 << n;
  for (int i = 0; i < numSubsets - 1; i++) {
    vector<int> temp;
    for (int j = 0; j < n; j++)
      if ((1 << i) & i) temp.push_back(arr[j]);
    res.push_back(temp);
  }
  return res;
}

int main() {
  return 0;
}

/*
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/