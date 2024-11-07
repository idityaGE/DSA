#include <bits/stdc++.h>
using namespace std;

// Brute Force
void solve(vector<int>& arr, vector<string>& res, vector<int>& subset, int freq[]) {
  if (subset.size() == arr.size()) {
    string s = "";
    for (int i = 0; i < subset.size(); i++)
      s = s + to_string(subset[i]);
    res.push_back(s);
    return;
  }

  for (int i = 0; i < arr.size(); i++) {
    if (!freq[i]) {
      subset.push_back(arr[i]);
      freq[i] = 1;
      solve(arr, res, subset, freq);
      freq[i] = 0;
      subset.pop_back();
    }
  }
}
string getPermutation_b(int n, int k) {
  int freq[n];
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    freq[i] = 0;
    arr[i] = i + 1;
  }
  vector<string> res;
  vector<int> subset;

  solve(arr, res, subset, freq);

  return res[k - 1];
}

// optimal
string getPermutation(int n, int k) {
  int fact = 1;
  vector<int> nums;
  for (int i = 1; i < n; i++) {
    fact *= i;
    nums.push_back(i);
  }
  nums.push_back(n);
  string ans = "";
  k = k - 1;
  while (1) {
    ans = ans + to_string(nums[k / fact]);
    nums.erase(nums.begin() + k / fact);
    if (nums.size() == 0) break;
    k = k % fact;
    fact = fact / nums.size();
  }
  return ans;
}

int main() {
  string s = getPermutation(9, 278082);
  cout << s << endl;
  return 0;
}



/*
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
*/