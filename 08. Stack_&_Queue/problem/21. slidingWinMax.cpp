#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  int n = nums.size();

  deque<int> dq;
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    // removing after every k the element in deque
    if (!dq.empty() && dq.front() <= i - k)
      dq.pop_front();

    // maintaining the monotonic stack
    while (!dq.empty() && nums[dq.back()] <= nums[i])
      dq.pop_back();

    dq.push_back(i);

    if (i >= k - 1)  // inserting start from k-1 index
      ans.push_back(nums[dq.front()]);
  }

  return ans;
}

int main() {
  return 0;
}

/*
Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/