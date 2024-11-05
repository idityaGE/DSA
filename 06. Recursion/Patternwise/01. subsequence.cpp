// [ 1, 3, 5, 6, 2, 9 ]
/*
**  sequence  --> only contigious
  1, 3, 5
  3, 5, 6

  1, 5, 6 --> X
  6, 2, 1 --> X
*/

/*
** subsequence --> contigious or noncontigious sequence, which follow the order
  1, 5, 2
  1, 3, 5
  5, 2, 9 => non-contigious but order is maintained

  5, 2, 1 --> X
  6, 5, 3 --> X
*/

#include <bits/stdc++.h>
using namespace std;

void printSubSeq(int index, vector<int> &ds, vector<int> &arr, int n) {
  // base condition
  if (index == n) {
    if (ds.size() == 0) cout << "[]" << endl;
    for (auto i : ds) cout << i << "  ";
    cout << endl;
    return;
  }

  // first pick
  ds.push_back(arr[index]);
  printSubSeq(index + 1, ds, arr, n);
  ds.pop_back();

  // then not pick
  printSubSeq(index + 1, ds, arr, n);
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  vector<int> ds;
  printSubSeq(0, ds, arr, n);
  return 0;
}

// TC --> O(2^n)
// SC --> auxilary(recursion stack tree space) O(n)

/*
input :
3
3 1 2

output :
3  1  2
3  1
3  2
3
1  2
1
2
[]
*/

/* ** LeetCode 78 -> Subsets
  vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res;
      vector<int> subset;
      createSubset(nums,0, res, subset);
      return res;
  }
  void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int> &subset) {
      if (index == nums.size()) {
          res.push_back(subset);
          return;
      }
      subset.push_back(nums[index]);
      createSubset(nums, index + 1, res, subset);
      subset.pop_back();
      createSubset(nums, index + 1, res, subset);
  }
*/
