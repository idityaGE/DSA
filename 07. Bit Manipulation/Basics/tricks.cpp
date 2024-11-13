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

// set ith bit
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

// remove the last set bit (right most)
// trick -  observe that the last bit is inverted
// n = 16 = 1000 , n-1 = 15 = 0111,
// n = 40 = 101000, n-1 = 39 = 100111,
int removeLastSetBit(int n) {
  return n & (n - 1);
}

int setLastUnsetBit(int n) {
  return n | (n + 1);
}

// check if numbers is power 2 or not
// trick - observe its binary will have only one 1's bit
// n = 32 = 100000, n = 16 = 10000
bool isPowerOf2(int n) {
  return (n > 0) && ((n & (n - 1)) == 0);
}

// count no. of set bits
// STL - builtin_popcount(n);
int countSetBit(int n) {
  int cnt = 0;
  while (n > 0) {
    cnt += n & 1;  // take some examples and do dry run
    n >>= 1;
  }
  return cnt;

  // another method
  // while(n != 0) {
  //   n = n & (n - 1);
  //   cnt++;
  // }
}

// Test functions
void testSwap() {
  int a = 5, b = 8;
  swap(&a, &b);
  assert(a == 8 && b == 5);
}

void testIsSet() {
  assert(isSet(13, 2) == true);   // 13 = 1101, i = 2
  assert(isSet(13, 1) == false);  // 13 = 1101, i = 1
}

void testSetIt() {
  assert(set_it(9, 2) == 13);   // 9 = 1001, i = 2 -> 13 = 1101
  assert(set_it(13, 2) == 13);  // 13 = 1101, i = 2 -> 13 = 1101
}

void testClearIt() {
  assert(clear_it(13, 2) == 9);  // 13 = 1101, i = 2 -> 9 = 1001
  assert(clear_it(9, 2) == 9);   // 9 = 1001, i = 2 -> 9 = 1001
}

void testToggleIt() {
  assert(toggle_it(13, 2) == 9);   // 13 = 1101, i = 2 -> 9 = 1001
  assert(toggle_it(13, 1) == 15);  // 13 = 1101, i = 1 -> 15 = 1111
}

void testRemoveLastSetBit() {
  assert(removeLastSetBit(16) == 0);   // 16 = 10000 -> 0
  assert(removeLastSetBit(40) == 32);  // 40 = 101000 -> 32 = 100000
}

void testIsPowerOf2() {
  assert(isPowerOf2(16) == true);   // 16 = 10000
  assert(isPowerOf2(18) == false);  // 18 = 10010
}

void testCountSetBit() {
  assert(countSetBit(13) == 3);  // 13 = 1101 -> 3 set bits
  assert(countSetBit(16) == 1);  // 16 = 10000 -> 1 set bit
}

int main() {
  testSwap();
  testIsSet();
  testSetIt();
  testClearIt();
  testToggleIt();
  testRemoveLastSetBit();
  testIsPowerOf2();
  testCountSetBit();
  cout << "All tests passed!" << endl;
  return 0;
}