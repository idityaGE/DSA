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
  combinations(index, target - arr[index], arr, res, subset);
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
  combinations(0, 7, arr, res, subset);

  for (auto i : res) {
    for (auto j : i)
      cout << j << "  ";
    cout << endl;
  }
  return 0;
}

/*
Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
*/