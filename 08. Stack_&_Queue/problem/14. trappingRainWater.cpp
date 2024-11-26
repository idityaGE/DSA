#include <bits/stdc++.h>
using namespace std;

int trap_1(vector<int>& height) {
  int n = height.size();
  if (n == 0) return 0;  // edge case

  int leftMax = 0, rightMax = 0, water = 0;
  int maxheight = height[0], index = 0;

  // Find the index of the maximum height
  for (int i = 1; i < n; i++) {
    if (maxheight < height[i]) {
      maxheight = height[i];
      index = i;
    }
  }

  // Calculate water trapped on the left side of the max height
  for (int i = 0; i < index; i++) {
    if (leftMax > height[i])
      water += leftMax - height[i];
    else
      leftMax = height[i];
  }

  // Calculate water trapped on the right side of the max height
  for (int i = n - 1; i > index; i--) {
    if (rightMax > height[i])
      water += rightMax - height[i];
    else
      rightMax = height[i];
  }

  return water;
}

// Two pointer
int trap(vector<int>& arr) {
  int n = arr.size();
  if (n == 0)
    return 0;

  int leftMax = 0, rightMax = 0, water = 0;
  int l = 0, r = n - 1;
  while (l < r) {
    if (arr[l] <= arr[r]) {
      if (leftMax > arr[l])
        water += leftMax - arr[l];
      else
        leftMax = arr[l];
      l++;
    } else {
      if (rightMax > arr[r])
        water += rightMax - arr[r];
      else
        rightMax = arr[r];
      r--;
    }
  }
  return water;
}

int main() {
  return 0;
}