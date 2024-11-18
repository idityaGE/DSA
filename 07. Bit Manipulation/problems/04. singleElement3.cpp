#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
  long long XOR = 0;
  for (int i = 0; i < nums.size(); i++) {
    XOR ^= nums[i];
  }
  int rightmostSetBit = XOR & ~(XOR - 1);
  int b1 = 0, b2 = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] & rightmostSetBit)
      b1 ^= nums[i];
    else
      b2 ^= nums[i];
  }
  if (b1 > b2)
    return {b2, b1};
  else
    return {b1, b2};
}

int main() {
  return 0;
}