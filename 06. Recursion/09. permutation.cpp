#include <bits/stdc++.h>
using namespace std;

// #46. Permutations

void recurPermu(vector<vector<int>>& res, vector<int>& arr,
                vector<int>& subset, int freq[]) {
  if (subset.size() == arr.size()) {
    res.push_back(subset);
    return;
  }

  for (int i = 0; i < arr.size(); i++) {
    if (!freq[i]) {
      // take and mark
      subset.push_back(arr[i]);
      freq[i] = 1;
      recurPermu(res, arr, subset, freq);

      // remove and unmark
      freq[i] = 0;
      subset.pop_back();
    }
  }
}

// better approach not using extra space
void backtrack(vector<vector<int>>& res, vector<int>& arr, int index = 0) {
  if (index == arr.size()) {
    res.push_back(arr);
    return;
  }

  for (int i = index; i < arr.size(); i++) {
    // swap
    swap(arr[index], arr[i]);
    backtrack(res, arr, index + 1);

    // unswap
    swap(arr[index], arr[i]);
  }
}
vector<vector<int>> permute(vector<int> arr) {
  int n = arr.size();
  vector<vector<int>> res;
  backtrack(res, arr);
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<vector<int>> res;
  vector<int> subset;

  int freq[n];
  for (int i = 0; i < n; i++)
    freq[i] = 0;

  recurPermu(res, arr, subset, freq);

  for (auto i : res) {
    for (auto j : i)
      cout << j << "  ";
    cout << endl;
  }
  return 0;
}

/*
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
*/