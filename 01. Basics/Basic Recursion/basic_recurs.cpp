#include <bits/stdc++.h>
using namespace std;

// Recursion
// when fn call itself
void print_name(int count) {
  if (count == 0)
    return;
  cout << "Aditya" << endl;
  print_name(count - 1);
}

// pre recusion
void print_n_N(int n, int N) {
  if (n > N) return;
  cout << n << " ";
  print_n_N(n + 1, N);
}
void print_N_n(int n, int N) {
  if (N < n) return;
  cout << N << " ";
  print_N_n(n, N - 1);
}

// we can also change its behaviour by making it `pre` or `post` recusion

// post recusion  --> backtracking
void print_n_N1(int n, int N) {
  if (N < n) return;
  print_n_N1(n, N - 1);
  cout << N << " ";
}
void print_N_n1(int n, int N) {
  if (n > N) return;
  print_N_n1(n + 1, N);
  cout << n << " ";
}

int main() {
  int count = 8;
  // print_name(count);
  // print_n_N(5, 20);
  // print_N_n(1, 20);

  return 0;
}