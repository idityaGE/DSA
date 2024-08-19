#include <bits/stdc++.h>
using namespace std;

int HCF(int n1, int n2) {
  for (int i = min(n1, n2); i >= 1; i--)
    if (n1 % i == 0 && n2 % i == 0)
      return i;
}  // O(min(n1,n2))

//** Euclidean Algorithm **//
// gcd(a,b) == gcd(a-b,b)  if a>b;
// gcd(a,b) == gcd(a%b,b)  if a>b;

int gcd(int a, int b) {
  if (a == 0)
    return b;
  else if (b == 0)
    return a;
  gcd(max(a, b) % min(a, b), min(a, b));

  // or instead of recussion
  // while (a > 0 && b > 0) {
  //   if (a > b)
  //     a %= b;
  //   else
  //     b %= a;
  // }
  // if (a == 0)
  //   return b;
  // else
  //   return a;
}  // O(log~(min(n1,n2))) 

int main() {
  int n1, n2;
  cin >> n1 >> n2;
  cout << gcd(n1, n2);
  return 0;
}