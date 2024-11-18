#include <bits/stdc++.h>
using namespace std;

int f(int n) {
  int rem = n % 4;
  switch (rem) {
    case 0:
      return n;
    case 1:
      return 1;
    case 2:
      return n + 1;
    default:
      return 0;
  }
}
int findXOR(int l, int r) {
  // int XOR = 0;
  // for(int i = l; i <= r; i++)
  //     XOR = XOR ^ i;
  // return XOR;

  return f(l - 1) ^ f(r);
}

int main() {
  return 0;
}