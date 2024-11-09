#include <bits/stdc++.h>
using namespace std;

// swap 2 numbers
void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;  // (a ^ b) ^ b ==> a
  *a = *a ^ *b;  // (a ^ b) ^ b ==> (a ^ b) ^ a ==> b
}

// Check if ith bit is set -> If the given number's ith bit (from the right) is 1 -> true, else false
bool isSet(int n, int i) {
  return (n & (1 << i)) != 0;  // Use left shift to check the bit
  // return ((n >> i) & 1) == 1;  // Use right shift to check the bit
}

// set the ith bit
// eg- binary = 1001, index = 2 ==> binary = 1101
//     binary = 1011, index = 1 ==> binary = 1011
//     only convert to 1 if its 0, if its 1 then leave as it is.
int set_it(int n, int i) {
  return (n | (1 << i));
}

// clear ith bit
// if ith bit is 1 then convert it into 0, if its 0 then leave it
int clear_it(int n, int i) {
  return (n & (~(1 << i)));
}

// toggle ith bit
int toggle_it(int n, int i) {
  return (n ^ (1 << i));
}

int main() {
  int a = 5;
  int b = 8;
  swap(&a, &b);
  cout << a << " " << b << endl;

  cout << isSet(13, 2) << endl;  // 13 = 1101, i = 2 ==> true -> 1
  cout << isSet(13, 1) << endl;  // 13 = 1101, i = 1 ==> false -> 0

  cout << set_it(9, 2) << endl;   // 9 = 1001 , i = 2 ==> 13 == 1101
  cout << set_it(13, 2) << endl;  // 13 = 1101 , i = 2 ==> 13 == 1101

  cout << clear_it(13, 2) << endl;  // 13 = 1101 , i = 2 ==> 9 == 1001
  cout << clear_it(9, 2) << endl;   // 9 = 1001 , i = 2 ==> 9 == 1001

  cout << toggle_it(13, 2) << endl;
  cout << toggle_it(13, 1) << endl;
  return 0;
}