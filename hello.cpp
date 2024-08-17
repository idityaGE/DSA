#include <iostream>
using namespace std;
void print10(int n) {
  for (int i = 1; i <= 2 * n - 1; i++) {
    int star = i;
    if (i > n) star = 2 * n - i;
    for (int j = 0; j < star; j++) {
      cout << "* ";
    }
    cout << endl;
  }
}
void print11(int n) {
  int start = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      start = 1;
    else
      start = 0;
    for (int j = 0; j <= i; j++) {
      cout << start << " ";
      start = 1 - start;
    }
    cout << endl;
  }
}
void print12(int n) {
  for (int i = 1; i <= n; i++) {
    // num
    for (int j = 1; j <= i; j++) {
      cout << j << " ";
    }
    // space
    for (int j = 1; j <= 2 * n - 2 * i; j++) {
      cout << "  ";
    }
    // num
    for (int j = i; j >= 1; j--) {
      cout << j << " ";
    }
    cout << endl;
  }
}
void print17(int n) {
  for (int i = 1; i < n; i++) {
    // space
    for (int j = 0; j < n - i - 1; j++) {
      cout << "  ";
    }
    // alphabets
    char ch = 'A';
    int breakpoint = (2 * i + 1) / 2;
    for (int j = 0; j < 2 * i - 1; j++) {
      cout << ch << " ";
      if (j <= breakpoint)
        ch++;
      else
        ch--;
    }
    // space
    for (int j = 0; j < n - i - 1; j++) {
      cout << "  ";
    }
    cout << endl;
  }
}
void print19(int n) {
  // * * * * * * * * * *
  // * * * *     * * * *
  // * * *         * * *
  // * *             * *
  // *                 *
  // *                 *
  // * *             * *
  // * * *         * * *
  // * * * *     * * * *
  // * * * * * * * * * *
  int space = 0;
  // upper part
  for (int i = 0; i < n; i++) {
    // star
    for (int j = n - i; j >= 1; j--) {
      cout << "* ";
    }
    // space
    for (int j = 1; j <= space; j++) {
      cout << "  ";
    }
    // star
    for (int j = n - i; j >= 1; j--) {
      cout << "* ";
    }
    space += 2;
    cout << endl;
  }
  // lower part
  space = 2 * n - 2;
  for (int i = 1; i <= n; i++) {
    // star
    for (int j = 1; j <= i; j++) {
      cout << "* ";
    }
    // space
    for (int j = 1; j <= space; j++) {
      cout << "  ";
    }
    // star
    for (int j = 1; j <= i; j++) {
      cout << "* ";
    }
    space -= 2;
    cout << endl;
  }
}
void print21(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0 || j == n - 1 || i == n - 1)
        cout << "* ";
      else
        cout << "  ";
    }
    cout << endl;
  }
}
void print22(int n) {
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top, bottom, right, left;
      top = i, left = j;
      bottom = (2 * n - 2) - i, right = (2 * n - 2) - j;
      cout << (n - min(min(top, bottom), min(left, right))) << " ";
    }
    cout << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    print22(n);
  }
  return 0;
}