#include <bits/stdc++.h>
using namespace std;

void print_all_divisor(int n) {
  for (int i = 0; i <= n; i++)
    if (n % i == 0) cout << i << endl;
}

// better approch
void print_divisor(int n) {
  for (int i = 1; i * i <= n /*[i <= sqrt(n);]*/; i++)
    if (n % i == 0)
      cout << i << " x " << n / i << " = 36" << endl;
  // if(n / i != i) v.emplace_back(n/i);
  // sort after that
}

int main() {
  int n;
  cin >> n;
  print_divisor(n);
  return 0;
}