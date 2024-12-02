#include <bits/stdc++.h>
using namespace std;

bool isMonotonic(vector<int>& nums) {
  int n = nums.size();
  int inc = 0, dec = 0;

  for (int i = 0; i < n - 1; i++) {
    if (nums[i] <= nums[i + 1]) inc++;
    if (nums[i] >= nums[i + 1]) dec++;
  }

  if (inc == nums.size() - 1 || dec == nums.size() - 1)
    return true;

  return false;
}

int main() {
  return 0;
}

/*
Example 1:

Input: nums = [1,2,2,3]
Output: true
Example 2:

Input: nums = [6,5,4,4]
Output: true
Example 3:

Input: nums = [1,3,2]
Output: false

*/