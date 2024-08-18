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
  vector<int> v;      // --> {}
  v.push_back(1);     // --> {1}
  v.emplace_back(2);  // --> {1, 2}

  vector<pair<int, int>> vp;
  vp.push_back({1, 2});
  vp.emplace_back(1, 2);  // automatically considered as a pair and pushed into the vector

  vector<int> v1(5, 10);  // --> {10, 10, 10, 10, 10}
  vector<int> v2(5);      // --> {0, 0, 0, 0, 0}

  vector<int> v3(v1);     // --> {10, 10, 10, 10, 10}  // copy of `v1`

  // iterator
  vector<int>::iterator it = v.begin();  // points to the first element of vector v
  cout << *(it) << endl;
  it++;
  cout << *(it) << endl;

  vector<int>::iterator it1 = v.end();  // points to memory address just after the last element
  it1--;                                // after `it1--;` it will point to the last element of the vector
  cout << *(it1) << endl;

  vector<int>::reverse_iterator it2 = v1.rend();    // points to the address before the first element
  vector<int>::reverse_iterator it3 = v1.rbegin();  // points to the last element of the vector

  cout << v[0] << " " << v.at(0) << endl;  // element at index zero
  cout << v.back() << endl;                // last element

  for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;

  for (auto it = v1.begin(); it != v1.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;

  for (auto it : v1) {
    cout << it << " ";
  }
  cout << endl;

  vector<int> v5 = {10, 6, 34, 65, 22, 6};
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // erase
  v5.erase(v5.begin() + 1);  // erase element at index 1
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  v5.erase(v5.begin() + 2, v5.begin() + 4);  // erase elements from index 2 to 3
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // insert
  v5.insert(v5.begin() + 2, 9);
  v5.insert(v5.begin() + 3, 10);
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // insert multiple elements
  v5.insert(v5.begin() + 2, 4, 7);  // insert 4 occurrences of 7 at index 2
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // insert another vector
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

  v5.clear();  // remove all elements

  cout << (v5.empty() ? "Yes" : "No") << endl;  // return true if vector is empty

  // List
  list<int> ls;
  ls.push_back(5);
  ls.emplace_back(9);
  ls.push_front(7);
  ls.emplace_front(3);
  for (auto it : ls)
    cout << it << " ";
  cout << endl;
  // other functions are the same as vector

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

  // Stack --> LIFO
  stack<int> st;
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
  cout << st.size() << endl;
  cout << (st.empty() ? "Yes" : "No") << endl;

  // Queue --> FIFO
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.emplace(4);

  q.back() += 5;
  cout << q.back() << endl;
  cout << q.front() << endl;

  q.pop();
  cout << q.front() << endl;

  // priority_queue
  // max heap
  priority_queue<int> pq;
  pq.push(5);
  pq.push(2);
  pq.push(8);
  pq.emplace(10);

  cout << pq.top() << endl;
  pq.pop();
  cout << pq.top() << endl;

  // min heap
  priority_queue<int, vector<int>, greater<int>> mq;
  mq.push(5);
  mq.push(2);
  mq.push(8);
  mq.emplace(10);

  cout << mq.top() << endl;
  mq.pop();
  cout << mq.top() << endl;

  // Set
  set<int> st_set;
  st_set.insert(1);
  st_set.emplace(2);
  st_set.insert(4);
  st_set.insert(5);
  st_set.insert(3);

  auto it4 = st_set.find(3);
  st_set.erase(3);

  int count_1 = st_set.count(1);

  auto it5 = st_set.find(2);
  st_set.erase(it5);

  auto it6 = st_set.lower_bound(2);
  auto it7 = st_set.upper_bound(5);

  // multiset
  multiset<int> ms;
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);

  ms.erase(1);
  ms.insert(1);
  ms.erase(ms.find(1));

  // unordered_set
  unordered_set<int> us;
  for (int i = 1; i <= 10; i++) {
    us.insert(i);
  }

  cout << "Elements present in the unordered set: ";
  for (auto it = us.begin(); it != us.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  int n = 2;
  if (us.find(2) != us.end())
    cout << n << " is present in the unordered set" << endl;

  us.erase(us.begin());
  cout << "Elements after deleting the first element: ";
  for (auto it = us.begin(); it != us.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "The size of the unordered set is: " << us.size() << endl;

  if (!us.empty())
    cout << "The unordered set is not empty" << endl;
  else
    cout << "The unordered set is empty" << endl;

  us.clear();
  cout << "Size of the unordered set after clearing all the elements: " << us.size() << endl;

  return 0;
}
