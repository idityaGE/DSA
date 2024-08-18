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
  vector<int> v;      // Declaring an empty vector
  v.push_back(1);     // Add element 1 to the end of the vector
  v.emplace_back(2);  // Similar to `push_back`, but slightly more efficient for non-primitives

  // Vector of pairs
  vector<pair<int, int>> vp;
  vp.push_back({1, 2});   // Adding a pair using push_back
  vp.emplace_back(1, 2);  // Adding a pair using emplace_back (more efficient)

  // Initializing vectors with default values
  vector<int> v1(5, 10);  // Creates a vector of size 5, initialized with 10s: {10, 10, 10, 10, 10}
  vector<int> v2(5);      // Creates a vector of size 5, initialized with 0s: {0, 0, 0, 0, 0}

  // Copying a vector
  vector<int> v3(v1);  // Copy of v1: {10, 10, 10, 10, 10}

  // **ITERATORS**
  // Iterators are used to point to the memory addresses of STL containers.
  vector<int>::iterator it = v.begin();                    // `it` points to the first element of vector v
  cout << "First element in vector v: " << *(it) << endl;  // Dereferencing to get the value
  it++;                                                    // Moving the iterator to the next element
  cout << "Second element in vector v: " << *(it) << endl;

  vector<int>::iterator it1 = v.end();  // `it1` points to the position just after the last element
  it1--;                                // Move `it1` back to the last element
  cout << "Last element in vector v: " << *(it1) << endl;

  // Reverse iterators allow you to iterate through the container in reverse order
  vector<int>::reverse_iterator it2 = v1.rend();    // Points to the element before the first element
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
  v5.insert(v5.begin() + 2, 9);   // Insert 9 at index 2
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
  vector<int> v6(3, 5);                         // {5, 5, 5}
  v5.insert(v5.begin(), v6.begin(), v6.end());  // Insert the contents of v6 at the beginning of v5
  cout << "After inserting another vector: ";
  for (auto it : v5)
    cout << it << " ";
  cout << endl;

  // Vector size and clearing elements
  cout << "Size of v5: " << v5.size() << endl;
  v5.pop_back();  // Remove the last element
  v5.swap(v6);    // Swap the contents of v5 and v6
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
  ls.push_back(5);      // Add element to the end
  ls.emplace_back(9);   // Add element to the end (more efficient than push_back)
  ls.push_front(7);     // Add element to the front
  ls.emplace_front(3);  // Add element to the front (more efficient than push_front)
  cout << "Elements in list ls: ";
  for (auto it : ls)
    cout << it << " ";
  cout << endl;

  // **DEQUE**
  // Deques are double-ended queues that allow efficient insertion and deletion from both ends
  deque<int> dq;
  dq.push_back(5);      // Add element to the end
  dq.emplace_back(2);   // Add element to the end
  dq.push_front(7);     // Add element to the front
  dq.emplace_front(2);  // Add element to the front
  dq.pop_back();        // Remove element from the end
  dq.pop_front();       // Remove element from the front
  cout << "Elements in deque dq: ";
  for (auto it : dq)
    cout << it << " ";
  cout << endl;

  cout << "Front element in dq: " << dq.front() << endl;
  cout << "Back element in dq: " << dq.back() << endl;

  // **STACK**
  // Stacks are LIFO (Last In First Out) structures
  stack<int> st;
  st.push(1);                                               // Add element to the stack
  st.push(2);                                               // Add element to the stack
  st.push(3);                                               // Add element to the stack
  st.push(4);                                               // Add element to the stack
  st.push(5);                                               // Add element to the stack
  st.emplace(9);                                            // Add element to the stack (more efficient than push)
  cout << "Top element in stack st: " << st.top() << endl;  // Get the top element
  st.pop();                                                 // Remove the top element
  st.pop();                                                 // Remove the next top element
  cout << "Top element after popping: " << st.top() << endl;
  cout << "Size of stack st: " << st.size() << endl;
  cout << "Is stack st empty? " << (st.empty() ? "Yes" : "No") << endl;

  // **QUEUE**
  // Queues are FIFO (First In First Out) structures
  queue<int> q;
  q.push(1);      // Add element to the queue
  q.push(2);      // Add element to the queue
  q.push(3);      // Add element to the queue
  q.emplace(4);   // Add element to the queue (more efficient than push)
  q.back() += 5;  // Modify the last element
  cout << "Back element in queue q after modification: " << q.back() << endl;
  cout << "Front element in queue q: " << q.front() << endl;
  q.pop();  // Remove the front element
  cout << "Front element after popping: " << q.front() << endl;

  // **PRIORITY_QUEUE**
  // Priority queues are heaps where the largest (or smallest) element has the highest priority
  // Max heap (default)
  priority_queue<int> pq;
  pq.push(5);                                                  // Add element
  pq.push(2);                                                  // Add element
  pq.push(8);                                                  // Add element
  pq.emplace(10);                                              // Add element (more efficient)
  cout << "Top element in max-heap pq: " << pq.top() << endl;  // Get the largest element
  pq.pop();                                                    // Remove the top element
  cout << "Top element after popping: " << pq.top() << endl;

  // Min heap
  priority_queue<int, vector<int>, greater<int>> mq;
  mq.push(5);                                                  // Add element
  mq.push(2);                                                  // Add element
  mq.push(8);                                                  // Add element
  mq.emplace(10);                                              // Add element (more efficient)
  cout << "Top element in min-heap mq: " << mq.top() << endl;  // Get the smallest element
  mq.pop();                                                    // Remove the top element
  cout << "Top element after popping: " << mq.top() << endl;

  // **SET**
  // Sets are sorted and unique collections of elements
  set<int> st_set;
  st_set.insert(1);   // Add element
  st_set.emplace(2);  // Add element (more efficient)
  st_set.insert(4);   // Add element
  st_set.insert(5);   // Add element
  st_set.insert(3);   // Add element

  auto it4 = st_set.find(3);  // Find the element 3
  st_set.erase(3);            // Remove the element 3

  int count_1 = st_set.count(1);  // Check if element 1 is in the set

  auto it5 = st_set.find(2);  // Find the element 2
  st_set.erase(it5);          // Remove the element pointed by the iterator

  auto it6 = st_set.lower_bound(2);  // Get the first element that is not less than 2
  auto it7 = st_set.upper_bound(5);  // Get the first element that is greater than 5

  // **MULTISET**
  // Multisets are sorted collections that allow duplicate elements
  multiset<int> ms;
  ms.insert(1);  // Add element
  ms.insert(1);  // Add duplicate element
  ms.insert(1);  // Add duplicate element
  ms.insert(1);  // Add duplicate element

  ms.erase(1);           // Remove all occurrences of 1
  ms.insert(1);          // Add element
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

  // **MAP**
  // A map stores elements in key-value pairs, where each key is unique and stored in sorted order.
  // The map is typically used when you need to quickly find, add, or remove elements based on a key.

  map<int, int> mpp;              // Declare a map with int keys and int values
  map<int, pair<int, int>> mpp1;  // Declare a map with int keys and pair<int, int> values

  // Adding elements to the map
  mpp[1] = 2;          // Add a key-value pair {1, 2} to the map
  mpp.emplace(3, 5);   // Add a key-value pair {3, 5} using emplace (more efficient than insert)
  mpp.insert({2, 4});  // Add a key-value pair {2, 4} using insert
  // Note: Keys in the map are unique and stored in sorted order

  mpp1[10] = {2, 3};  // Add a key-value pair {{2, 3}, 10} to the map mpp1

  // Iterating through the map and printing each key-value pair
  for (auto it : mpp)
    cout << it.first << " " << it.second << endl;

  // Accessing values using keys
  cout << "Value at key 1: " << mpp[1] << endl;  // Output: 2
  cout << "Value at key 5: " << mpp[5] << endl;  // No key 5, returns 0 (default for int)

  // Finding elements in the map
  auto it87 = mpp.find(3);  // Find the iterator pointing to the key-value pair with key 3
  if (it87 != mpp.end())
    cout << "Found: " << it87->second << endl;  // Output the value if found

  auto it98 = mpp.find(5);  // Try to find a key that doesn't exist
  if (it98 == mpp.end())
    cout << "Key 5 not found!" << endl;  // Output if the key is not found

  // Lower and upper bounds
  auto lb = mpp.lower_bound(2);  // Get an iterator to the first element that is not less than 2
  auto ub = mpp.upper_bound(3);  // Get an iterator to the first element that is greater than 3

  // Common operations such as erase, size, swap, and empty also work with maps
  mpp.erase(2);                                // Erase the element with key 2
  cout << "Map size: " << mpp.size() << endl;  // Output the current size of the map

  // **MULTIMAP**
  // A multimap is similar to a map but allows duplicate keys. Elements are stored in sorted order based on keys.
  // Unlike map, you cannot use mpp[key] syntax to access elements.

  multimap<int, int> mmp;  // Declare a multimap with int keys and int values
  mmp.insert({1, 2});      // Add a key-value pair {1, 2}
  mmp.insert({1, 3});      // Add a duplicate key {1, 3}
  mmp.insert({2, 4});      // Add a key-value pair {2, 4}

  // Iterating through the multimap and printing each key-value pair
  for (auto it : mmp)
    cout << it.first << " " << it.second << endl;

  // **UNORDERED_MAP**
  // An unordered_map is similar to a map but does not store elements in sorted order. It uses a hash table for storage,
  // which provides average O(1) time complexity for insertions, deletions, and access.
  // However, the worst-case time complexity for these operations is O(n).

  unordered_map<int, int> umpp;  // Declare an unordered_map with int keys and int values
  umpp[1] = 2;                   // Add a key-value pair {1, 2}
  umpp[2] = 3;                   // Add a key-value pair {2, 3}
  umpp[3] = 4;                   // Add a key-value pair {3, 4}

  // Iterating through the unordered_map and printing each key-value pair
  for (auto it : umpp)
    cout << it.first << " " << it.second << endl;

  // Erasing and checking size
  umpp.erase(2);                                          // Erase the element with key 2
  cout << "Unordered map size: " << umpp.size() << endl;  // Output the current size of the unordered_map

  // **SOME_EXTRA**

  // **Sorting**
  // The `sort` function is used to sort elements in a range.
  // By default, it sorts in increasing order.

  vector<int> v8 = {4, 2, 5, 3, 1};

  sort(v8.begin(), v8.end());  // Sort in increasing order: {1, 2, 3, 4, 5}

  sort(v8.begin(), v8.end(), greater<int>());  // Sort in decreasing order: {5, 4, 3, 2, 1}

  sort(v8.rbegin(), v8.rend());  // Another way to sort in decreasing order: {5, 4, 3, 2, 1}
  // `rbegin()` and `rend()` reverse the range.

  // **Sorting with a Custom Comparator**
  // We can sort complex data structures like pairs using custom comparator functions.
  pair<int, int> ap1[] = {{1, 2}, {2, 1}, {4, 1}};

  // Custom comparator to sort `ap1`:
  // 1. First, sort by the second element of the pair in increasing order.
  // 2. If the second elements are the same, then sort by the first element in decreasing order.
  auto comp = [](pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;
    return p1.first > p2.first;
  };

  int n9 = sizeof(ap1) / sizeof(ap1[0]);
  sort(ap1, ap1 + n9, comp);

  // After sorting, `ap1` would be: {{4, 1}, {2, 1}, {1, 2}}

  // **Counting the Number of 1s in Binary Representation**
  int num = 7;
  // The __builtin_popcount function returns the number of 1-bits in the binary representation of `num`.
  int cnt_1 = __builtin_popcount(num);  // 7 in binary is 111, so cnt_1 = 3

  long long num2 = 213871528369;
  // For long long integers, use __builtin_popcountll.
  int cnt_ll = __builtin_popcountll(num2);

  // **Generating All Permutations of a String**
  string s = "123";
  // `next_permutation` generates the next lexicographically greater permutation.
  do {
    cout << s << endl;
  } while (next_permutation(s.begin(), s.end()));

  // Output will be:
  // 123
  // 132
  // 213
  // 231
  // 312
  // 321

  return 0;
}
