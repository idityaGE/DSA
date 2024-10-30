#include <bits/stdc++.h>
using namespace std;

int sum_of_n(int n) {
  if (n == 1) return 1;
  return sum_of_n(n - 1) + n;
}

int pow_of_n(int x, int n) {
  if (n == 0) return 1;
  return x * pow_of_n(x, n - 1);
}

int factorial_of_n(int n) {
  if (n == 1) return 1;
  return n * factorial_of_n(n - 1);
}

// --> 0, 1, 1, 2, 3, 5, 8, 13, ...
int fibonacci_series(int n) {
  if (n == 2) return 1;
  if (n == 1) return 0;
  return fibonacci_series(n - 1) + fibonacci_series(n - 2);
}

void reverse_arr_2pointer(int arr[], int st, int end) {
  if (st >= end) return;
  swap(arr[st], arr[end]);
  reverse_arr(arr, st + 1, end - 1);
}

// better method using single value 
void reverse_arr(int arr[], int n, int i = 0) { // default parameter
  if (i >= n / 2) return;
  swap(arr[i], arr[n - i - 1]);
  reverse_arr(arr, n, i + 1);
}

bool check_palindrome(string &st, int i = 0) {
  if (i >= st.size() / 2) return true;
  if (st[i] != st[st.size() - i - 1]) return false;
  check_palindrome(st, i + 1);
}

int main() {
  cout << sum_of_n(5) << endl;
  cout << pow_of_n(2, 3) << endl;
  cout << factorial_of_n(4) << endl;

  int arr[5] = {1, 2, 3, 4, 6};
  reverse_arr(arr, 5);
  for (int i = 0; i < 5; i++) cout << arr[i] << " ";
  cout << endl;

  string st = "maddam";
  cout << check_palindrome(st);

  return 0;
}