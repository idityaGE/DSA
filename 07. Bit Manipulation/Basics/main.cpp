#include <bits/stdc++.h>
using namespace std;

string DecimalToBinary(int n) {
  string ans = "";
  while (n != 1) {
    if (n % 2 == 1)
      ans += '1';
    else
      ans += '0';
    n >>= 1;  // n /= 1
  }
  ans += '1';
  reverse(ans.begin(), ans.end());
  return ans;
}

int BinaryToDecimal(string s) {
  int ans = 0;
  int len = s.length();
  int binary = stoi(s);
  for (int i = len - 1; i >= 0; i--) {
    ans += (binary % 10) * (1 << (len - i - 1));
    binary /= 10;
  }
  return ans;
}

// AND --> &

// OR --> |

// XOR --> ^
//   1 ^ 1 = 0  ==> even no. of n then 0
//   1 ^ 0 = 1  ==> odd no. of n then 1

// RIGHT SWIFT --> >>
//    x >> k == x / pow(2, k);

// LEFT SWIFT --> <<
//    x << k == x * pow(2, k);

// NOT --> ~
// 0 -> 1, 1 -> 2

int main() {
  cout << DecimalToBinary(13);
  cout << endl;
  cout << BinaryToDecimal("1001");
  return 0;
}