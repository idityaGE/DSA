#include <bits/stdc++.h>
using namespace std;

void subset_uni(vector<int> &arr, vector<vector<int>> &subsets, vector<int> &subset, int index = 0) {
  subsets.push_back(subset);
  for (int i = index; i < arr.size(); i++) {
    if (i != index && arr[i] == arr[i - 1]) continue;
    subset.push_back(arr[i]);
    subset_uni(arr, subsets, subset, i + 1);
    subset.pop_back();
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<vector<int>> subsets;
  vector<int> subset;
  sort(arr.begin(), arr.end());

  subset_uni(arr, subsets, subset);

  for (auto i : subsets) {
    for (auto j : i)
      cout << j << "  ";
    cout << endl;
  }

  return 0;
}

/*
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/