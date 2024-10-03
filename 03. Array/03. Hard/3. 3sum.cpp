#include <bits/stdc++.h>
using namespace std;

//! Brute Force
vector<vector<int>> triplet_brute(int n, vector<int> &arr) {
  set<vector<int>> st;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++)
        if (arr[i] + arr[j] + arr[k] == 0) {
          vector<int> temp = {arr[i], arr[j], arr[k]};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// Better
vector<vector<int>> triplet_better(int n, vector<int> &arr) {
  set<vector<int>> st;
  for (int i = 0; i < n - 1; i++) {
    // re-initialize hash set when i move
    set<int> hashSet;
    for (int j = i + 1; j < n; j++) {
      int k = -(arr[i] + arr[j]);
      if (hashSet.find(k) != hashSet.end()) {
        vector<int> temp = {arr[i], arr[j], k};
        sort(temp.begin(), temp.end());
        st.insert(temp);
      }
      // insert in hash when j moves
      hashSet.insert(arr[j]);
    }
  }
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}

// Optimal
vector<vector<int>> threeSum_optimal(vector<int> &arr) {
  // for dry run use this --> [-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2]
  int n = arr.size();
  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++) {
    if (i > 0 && arr[i] == arr[i - 1])
      continue;
    int j = i + 1;
    int k = n - 1;
    while (j < k) {
      int sum = arr[i] + arr[j] + arr[k];
      if (sum < 0)
        j++;
      else if (sum > 0)
        k--;
      else {
        vector<int> temp = {arr[i], arr[j], arr[k]};
        ans.push_back(temp);
        j++;
        k--;
        while (j < k && arr[j] == arr[j - 1]) j++;
        while (j < k && arr[k] == arr[k + 1]) k--;
      }
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<vector<int>> ans = threeSum_optimal(arr);
  for (auto it : ans) {
    for (auto i : it)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}