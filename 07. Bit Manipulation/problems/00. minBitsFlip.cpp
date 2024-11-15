#include <bits/stdc++.h>
using namespace std;

int minBitFilps(int start, int goal) {
  int xorResult = start ^ goal;  // this will tell which bits needs to be fliped
  int count = 0;
  while (xorResult) { // count no. of set bits
    count += xorResult & 1;
    xorResult >>= 1;
  }
  return count;
}

int main() {
  return 0;
}

/*
Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
*/