#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
  if (n < 0) {
    x = 1 / x;
    if (n == INT_MIN) {
      n += 1;
      n *= (-1);
      double b = myPow(x, n / 2);
      if (n % 2 == 0)
        return b * b;
      else
        return x * b * b * x;
    }
    n *= (-1);
  }
  if (n == 0) return 1;
  double a = myPow(x, n / 2);
  if (n % 2 == 0)
    return a * a;
  else
    return x * a * a;
}

int main() {
  int n, x;
  cin >> x >> n;
  if (n < 0) {
    int p = (-1) * n;
    long long res = pow(x, p);
    double result = float(1) / res;
    cout << result;
  } else
    cout << pow(x, n);
  return 0;
}

