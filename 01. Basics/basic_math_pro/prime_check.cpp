#include <bits/stdc++.h>
using namespace std;

bool prime_check(int n) {
  if (n == 1) {
    cout << "1 is neither prime nor composite." << endl;
    return 0;
  } else {
    for (int i = 2; i <= sqrt(n); i++) {
      if (n % i == 0) return 0;
    }
  }
  return 1;
}
// O(sqrt(n))
int main() {
  int n;
  cin >> n;
  cout << prime_check(n);
  return 0;
}