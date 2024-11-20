#include <bits/stdc++.h>
using namespace std;

class Stack {
  int size;   // Maximum size of the stack
  int top;    // Index of the top element
  int *s;     // Pointer to the stack array

 public:
  // Constructor
  Stack(int stackSize)
      : size(stackSize), top(-1), s(new int[stackSize]) {}

  // Push an element onto the stack
  void push(int val) {
    if (top == size - 1)
      throw runtime_error("Stack is full");
    s[++top] = val;
  }

  // Pop an element from the stack
  int pop() {
    if (isEmpty())
      throw runtime_error("Stack is empty");
    return s[top--];
  }

  // Get the top element of the stack
  int getTop() const {
    if (isEmpty())
      throw runtime_error("Stack is empty");
    return s[top];
  }

  // Check if the stack is empty
  bool isEmpty() const {
    return top == -1;
  }

  // Get the current number of elements in the stack
  int getSize() const {
    return top + 1;
  }

  // Destructor
  ~Stack() {
    delete[] s;
  }
};

int main() {
  try {
    Stack st(5);  // Create a stack with size 5
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.getTop() << endl;
    cout << "Stack size: " << st.getSize() << endl;

    cout << "Popping: " << st.pop() << endl;
    cout << "Stack size after pop: " << st.getSize() << endl;

    cout << "Popping all elements..." << endl;
    st.pop();
    st.pop();

    // Uncommenting the next line will throw an error
    // st.pop();

    cout << "Is stack empty? " << (st.isEmpty() ? "Yes" : "No") << endl;
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
