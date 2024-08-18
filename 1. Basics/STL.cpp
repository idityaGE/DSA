#include <bits/stdc++.h>
using namespace std;

int main() {
  // **PAIR**
  // A pair is a container that stores two heterogeneous objects as a single unit.
  pair<int, int> p = {1, 5};
  // Accessing the elements of the pair using `.first` and `.second`
  cout << "Pair p: " << p.first << " " << p.second << endl;

  // Nested pairs: A pair can contain another pair
  pair<int, pair<int, int>> pp = {3, {9, 7}};
  cout << "Nested Pair pp: " << pp.first << " " << pp.second.first << " " << pp.second.second << endl;

  // Array of pairs
  pair<int, int> parr[] = {{1, 2}, {2, 3}, {7, 8}};
  cout << "Second element's second value in parr: " << parr[1].second << endl;

  // **VECTOR**
  // Vectors are dynamic arrays that can change size.
  vector<int> v;  // Declaring an empty vector
  v.push_back(1);  // Add element 1 to the end of the vector
  v.emplace_back(2);  // Similar to `push_back`, but slightly more efficient for non-primitives

  // Vector of pairs
  vector<pair<int, int>> vp;
  vp.push_back({1, 2});  // Adding a pair using push_back
  vp.emplace_back(1, 2);  // Adding a pair using emplace_back (more efficient)

  // Initializing vectors with default values
  vector<int> v1(5, 10);  // Creates a vector of size 5, initialized with 10s: {10, 10, 10, 10, 10}
  vector<int> v2(5);  // Creates a vector of size 5, initialized with 0s: {0, 0, 0, 0, 0}

  // Copying a vector
  vector<int> v3(v1);  // Copy of v1: {10, 10, 10, 10, 10}

  // **ITERATORS**
  // Iterators are used to point to the memory addresses of STL containers.
  vector<int>::iterator it = v.begin();  // `it` points to the first element of vector v
  cout << "First element in vector v: " << *(it) << endl;  // Dereferencing to get the value
  it++;  // Moving the iterator to the next element
  cout << "Second element in vector v: " << *(it) << endl;

  vector<int>::iterator it1 = v.end();  // `it1` points to the position just after the last element
  it1--;  // Move `it1` back to the last element
  cout << "Last element in vector v: " << *(it1) << endl;

  // Reverse iterators allow you to iterate through the container in reverse order
  vector<int>::reverse_iterator it2 = v1.rend();  // Points to the element before the first element
  vector<int>::reverse_iterator it3 = v1.rbegin();  // Points to the last element

  // Accessing elements
  cout << "First element in v: " << v[0] << " (using []) and " << v.at(0) << " (using at())" << endl;
  cout << "Last element in v: " << v.back() << endl;

  // Different ways to iterate over a vector
  cout << "Iterating over v1 using iterator:" << endl;
  for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;

  cout << "Iterating over v1 using auto keyword:" << endl;
  for (auto it = v1.begin(); it != v1.end(); it++) {
    cout << *(it) << " ";
  }
  cout << endl;

  cout << "Range-based for loop to iterate over v1:" << endl;
  for (auto it : v1) {
    cout << it << " ";
  }
  cout << endl;

  // **VECTOR OPERATIONS**
  // Initializing a vector with specific elements
  vector<int> v5 = {10, 6, 34, 65, 22, 6};
  cout << "Initial vector v5: ";
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // Erase elements
  v5.erase(v5.begin() + 1);  // Erase element at index 1 (the second element)
  cout << "After erasing second element: ";
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // Erase a range of elements
  v5.erase(v5.begin() + 2, v5.begin() + 4);  // Erase elements from index 2 to 3
  cout << "After erasing elements from index 2 to 3: ";
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // Insert elements
  v5.insert(v5.begin() + 2, 9);  // Insert 9 at index 2
  v5.insert(v5.begin() + 3, 10);  // Insert 10 at index 3
  cout << "After inserting 9 and 10: ";
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // Insert multiple elements
  v5.insert(v5.begin() + 2, 4, 7);  // Insert 4 occurrences of 7 at index 2
  cout << "After inserting multiple 7s: ";
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // Insert another vector
  vector<int> v6(3, 5);  // {5, 5, 5}
  v5.insert(v5.begin(), v6.begin(), v6.end());  // Insert the contents of v6 at the beginning of v5
  cout << "After inserting another vector: ";
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // Vector size and clearing elements
  cout << "Size of v5: " << v5.size() << endl;
  v5.pop_back();  // Remove the last element
  v5.swap(v6);  // Swap the contents of v5 and v6
  cout << "After swapping v5 and v6, v5: ";
  for (auto it : v5)
    cout << it << " ";
  cout << endl;
  cout << "After swapping v5 and v6, v6: ";
  for (auto it : v6)
    cout << it << " ";
  cout << endl;

  // Clear the vector
  v5.clear();  // Remove all elements from v5
  cout << "Is v5 empty? " << (v5.empty() ? "Yes" : "No") << endl;

  // **LIST**
  // Lists are doubly linked lists that allow efficient insertion and deletion from both ends
  list<int> ls;
  ls.push_back(5);  // Add element to the end
  ls.emplace_back(9);  // Add element to the end (more efficient than push_back)
  ls.push_front(7);  // Add element to the front
  ls.emplace_front(3);  // Add element to the front (more efficient than push_front)
  cout << "Elements in list ls: ";
  for (auto it : ls)
    cout << it << " ";
  cout << endl;

  // **DEQUE**
  // Deques are double-ended queues that allow efficient insertion and deletion from both ends
  deque<int> dq;
  dq.push_back(5);  // Add element to the end
  dq.emplace_back(2);  // Add element to the end
  dq.push_front(7);  // Add element to the front
  dq.emplace_front(2);  // Add element to the front
  dq.pop_back();  // Remove element from the end
  dq.pop_front();  // Remove element from the front
  cout << "Elements in deque dq: ";
  for (auto it : dq)
    cout << it << " ";
  cout << endl;

  cout << "Front element in dq: " << dq.front() << endl;
  cout << "Back element in dq: " << dq.back() << endl;

  // **STACK**
  // Stacks are LIFO (Last In First Out) structures
  stack<int> st;
  st.push(1);  // Add element to the stack
  st.push(2);  // Add element to the stack
  st.push(3);  // Add element to the stack
  st.push(4);  // Add element to the stack
  st.push(5);  // Add element to the stack
  st.emplace(9);  // Add element to the stack (more efficient than push)
  cout << "Top element in stack st: " << st.top() << endl;  // Get the top element
  st.pop();  // Remove the top element
  st.pop();  // Remove the next top element
  cout << "Top element after popping: " << st.top() << endl;
  cout << "Size of stack st: " << st.size() << endl;
  cout << "Is stack st empty? " << (st.empty() ? "Yes" : "No") << endl;

  // **QUEUE**
  // Queues are FIFO (First In First Out) structures
  queue<int> q;
  q.push(1);  // Add element to the queue
  q.push(2);  // Add element to the queue
  q.push(3);  // Add element to the queue
  q.emplace(4);  // Add element to the queue (more efficient than push)
  q.back() += 5;  // Modify the last element
  cout << "Back element in queue q after modification: " << q.back() << endl;
  cout << "Front element in queue q: " << q.front() << endl;
  q.pop();  // Remove the front element
  cout << "Front element after popping: " << q.front() << endl;

  // **PRIORITY_QUEUE**
  // Priority queues are heaps where the largest (or smallest) element has the highest priority
  // Max heap (default)
  priority_queue<int> pq;
  pq.push(5);  // Add element
  pq.push(2);  // Add element
  pq.push(8);  // Add element
  pq.emplace(10);  // Add element (more efficient)
  cout << "Top element in max-heap pq: " << pq.top() << endl;  // Get the largest element
  pq.pop();  // Remove the top element
  cout << "Top element after popping: " << pq.top() << endl;

  // Min heap
  priority_queue<int, vector<int>, greater<int>> mq;
  mq.push(5);  // Add element
  mq.push(2);  // Add element
  mq.push(8);  // Add element
  mq.emplace(10);  // Add element (more efficient)
  cout << "Top element in min-heap mq: " << mq.top() << endl;  // Get the smallest element
  mq.pop();  // Remove the top element
  cout << "Top element after popping: " << mq.top() << endl;

  // **SET**
  // Sets are sorted and unique collections of elements
  set<int> st_set;
  st_set.insert(1);  // Add element
  st_set.emplace(2);  // Add element (more efficient)
  st_set.insert(4);  // Add element
  st_set.insert(5);  // Add element
  st_set.insert(3);  // Add element

  auto it4 = st_set.find(3);  // Find the element 3
  st_set.erase(3);  // Remove the element 3

  int count_1 = st_set.count(1);  // Check if element 1 is in the set

  auto it5 = st_set.find(2);  // Find the element 2
  st_set.erase(it5);  // Remove the element pointed by the iterator

  auto it6 = st_set.lower_bound(2);  // Get the first element that is not less than 2
  auto it7 = st_set.upper_bound(5);  // Get the first element that is greater than 5

  // **MULTISET**
  // Multisets are sorted collections that allow duplicate elements
  multiset<int> ms;
  ms.insert(1);  // Add element
  ms.insert(1);  // Add duplicate element
  ms.insert(1);  // Add duplicate element
  ms.insert(1);  // Add duplicate element

  ms.erase(1);  // Remove all occurrences of 1
  ms.insert(1);  // Add element
  ms.erase(ms.find(1));  // Remove a single occurrence of 1

  // **UNORDERED_SET**
  // Unordered sets are collections of unique elements stored in no particular order
  unordered_set<int> us;
  for (int i = 1; i <= 10; i++) {
    us.insert(i);  // Add elements 1 to 10
  }

  cout << "Elements in the unordered set: ";
  for (auto it = us.begin(); it != us.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  int n = 2;
  if (us.find(2) != us.end())
    cout << n << " is present in the unordered set" << endl;

  us.erase(us.begin());  // Remove the first element
  cout << "Elements after deleting the first element: ";
  for (auto it = us.begin(); it != us.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "The size of the unordered set: " << us.size() << endl;

  if (!us.empty())
    cout << "The unordered set is not empty" << endl;
  else
    cout << "The unordered set is empty" << endl;

  us.clear();  // Clear all elements in the unordered set
  cout << "Size of the unordered set after clearing: " << us.size() << endl;

  return 0;
}
