#include <bits/stdc++.h>
using namespace std;

void combinations(int index, int target, vector<int>& arr,
                  vector<vector<int>>& res, vector<int>& subset) {
  if (target == 0) {
    res.push_back(subset);
    return;
  }

  if (index >= arr.size() || target < 0)
    return;

  // pick the current element (can pick multiple times)
  subset.push_back(arr[index]);
  combinations(index + 1, target - arr[index], arr, res, subset);
  subset.pop_back();

  // not pick the current element
  combinations(index + 1, target, arr, res, subset);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  vector<vector<int>> res;
  vector<int> subset;
  combinations(0, 8, arr, res, subset);

  for (int i = 0; i < res.size(); i++)
    sort(res[i].begin(), res[i].end());

  sort(res.begin(), res.end());

  for (auto i : res) {
    for (auto j : i)
      cout << j << "  ";
    cout << endl;
  }
  return 0;
}

/*
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]
*/