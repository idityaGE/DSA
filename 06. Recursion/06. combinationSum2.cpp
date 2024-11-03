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

  for (int i = index; i < arr.size(); i++) {
    
    // Skip duplicates
    if (i > index && arr[i] == arr[i - 1])
      continue;

    subset.push_back(arr[i]);
    combinations(i + 1, target - arr[i], arr, res, subset);
    subset.pop_back();
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr.begin(), arr.end());

  vector<vector<int>> res;
  vector<int> subset;
  combinations(0, 8, arr, res, subset);

  // for (int i = 0; i < res.size(); i++)
  //   sort(res[i].begin(), res[i].end());

  // sort(res.begin(), res.end());

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