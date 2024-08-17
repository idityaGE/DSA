#include <iostream>
#include <vector>
using namespace std;

int main() {
  // pair
  pair<int, int> p = {1, 5};
  cout << p.first << " " << p.second << endl;

  pair<int, pair<int, int>> pp = {3, {9, 7}};
  cout << pp.first << " " << pp.second.first << " " << pp.second.second << endl;

  pair<int, int> parr[] = {{1, 2}, {2, 3}, {7, 8}};
  cout << parr[1].second << endl;

  // vector
  vector<int> v;      // --> {}
  v.push_back(1);     // --> {1}
  v.emplace_back(2);  // --> {1,2}   // `emplace_back` is faster than `push_back`

  vector<pair<int, int>> vp;
  vp.push_back({1, 2});
  vp.emplace_back(1, 2);     // automatically consider it as a pair and push in vector

  vector<int> v1(5, 10);     // -->  {10, 10, 10, 10, 10}
  vector<int> v2(5);         // -->  {0, 0, 0, 0, 0}

  vector<int> v3(v2);        // -->  {10, 10, 10, 10, 10}  // copy of the of `v1`





  return 0;
}