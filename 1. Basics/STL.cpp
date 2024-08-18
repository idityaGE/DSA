#include <bits/stdc++.h>
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
  // for more about vector --> https://github.com/idityaGE/class-assignment/blob/main/cpp/vector/intro.cpp
  vector<int> v;      // --> {}
  v.push_back(1);     // --> {1}
  v.emplace_back(2);  // --> {1,2}   // `emplace_back` is faster than `push_back`

  vector<pair<int, int>> vp;
  vp.push_back({1, 2});
  vp.emplace_back(1, 2);  // automatically consider it as a pair and push in vector

  vector<int> v1(5, 10);  // -->  {10, 10, 10, 10, 10}
  vector<int> v2(5);      // -->  {0, 0, 0, 0, 0}

  vector<int> v3(v2);  // -->  {10, 10, 10, 10, 10}  // copy of the of `v1`

  // iterator
  vector<int>::iterator it = v.begin();  // point to the first element of the vector v
  cout << *(it) << endl;
  it++;
  cout << *(it) << endl;

  vector<int>::iterator it1 = v.end();  // point to memory address just after the last element
  cout << *(it1) << endl;               // some random value
  it1--;                                // after `it1--;` it will point to last element of the vector
  cout << *(it1) << endl;

  vector<int>::reverse_iterator it2 = v1.rend();    // point to the address before first element and if we do `it2++` it will move in forward direction
  vector<int>::reverse_iterator it3 = v1.rbegin();  // point to last element of the vector and if we do `it3++` it will move in backward direction

  cout << v[0] << " " << v.at(0) << endl;  // element at index zero
  cout << v.back() << endl;                // last element

  for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {  // but this is very long
    cout << *(it) << " ";
  }
  cout << endl;
  // instead of using above syntax use:
  for (auto it = v1.begin(); it < v1.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;
  // there is better use also
  for (auto it : v1) {
    cout << it << " ";
  }
  cout << endl;

  vector<int> v5 = {10, 6, 34, 65, 22, 6};
  for (auto it : v5)
    cout << it << " ";
  cout << endl;
  // erase
  v5.erase(v5.begin() + 1);  // erase --> 6 [ index = 1 ]
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  v5.erase(v5.begin() + 2, v5.begin() + 4);  // --> for index 2 to 3, not 4th index --> [start,end)
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // insert
  v5.insert(v5.begin() + 2, 9);
  v5.insert(v5.begin() + 3, 10);
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // insert multiple element
  v5.insert(v5.begin() + 2, 4, 7);  // at index 2 insert 4 no. of 7
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // inserting another vector
  vector<int> v6(3, 5);
  v5.insert(v5.begin(), v6.begin(), v6.end());
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  cout << v5.size() << endl;

  v5.pop_back();  // remove the last element

  v5.swap(v6);  // swap both vector values
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  for (auto it : v6)
    cout << it << " ";
  cout << endl;

  v5.clear();  // remove all element

  cout << (v5.empty() ? "Yes" : "No") << endl;  // return true if vector is empty

  // List
  list<int> ls;
  ls.push_back(5);
  ls.emplace_back(9);
  // In list, we can use front operation which can only be performed in vector by using insert fn and insert function is costly than this below fn of list
  ls.push_front(7);
  ls.emplace_front(3);
  for (auto it : ls)
    cout << it << " ";
  cout << endl;
  // rest fn are same as vector
  // begin, end, clear, insert, size, swap, clear, empty, erase, pop_back

  // Deque
  deque<int> dq;
  dq.push_back(5);
  dq.emplace_back(2);
  dq.push_front(7);
  dq.emplace_front(2);
  dq.pop_back();
  dq.pop_front();
  for (auto it : dq)
    cout << it << " ";
  cout << endl;

  cout << dq.front() << endl;
  cout << dq.back() << endl;
  // rest fn are same as vector
  // begin, end, clear, insert, size, swap, clear, empty, erase, pop_back

  // Stack --> LIFO
  stack<int> st;
  // all of operation are O(1)
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.emplace(9);

  cout << st.top() << endl;
  st.pop();
  st.pop();
  cout << st.top() << endl;
  // here begin or end is not allowed
  cout << st.size() << endl;
  cout << (st.empty() ? "Yes" : "NO") << endl;
  stack<int> st1, st2;
  st1.swap(st2);  // swap

  // Queue --> FIFO
  queue<int> q;  // all operation happen in O(1)
  q.push(1);     // {1}
  q.push(2);     // {1,2}
  q.push(3);     // {1,2,3}
  q.emplace(4);  // {1,2,3,4}

  q.back() += 5;  // {1,2,3,9}
  cout << q.back() << endl;
  cout << q.front() << endl;

  q.pop();  // {2,3,9}
  cout << q.front() << endl;

  // priority_queue
  // max heap
  // value with largest value stay at the top
  priority_queue<int> pq;
  pq.push(5);      // {5}
  pq.push(2);      // {5,2}
  pq.push(8);      // {8,5,2}
  pq.emplace(10);  // {10,8,5,2}
  // data is not stored in linear manner its stored in tree data structure
  pq.top();  // 10
  pq.pop();  // {8,5,2}

  // minimum heap
  priority_queue<int, vector<int>, greater<int>> mq;
  mq.push(5);      // {5}
  mq.push(2);      // {2,5}
  mq.push(8);      // {2,5,8}
  mq.emplace(10);  // {2,5,8,10}

  cout << mq.top() << endl;
  mq.pop(); // {5,8,10}
  cout << mq.top() << endl;
  // push and pop happen in O(log(n))
  // top happen in O(1)

  return 0;
}