#include <bits/stdc++.h>
using namespace std;

class Queue {
  int front, rear, size; // front and rear indices, size = capacity
  int *q;               // dynamically allocated array for the queue

 public:
  // Constructor
  Queue(int queueSize)
      : front(-1), rear(-1), size(queueSize), q(new int[queueSize]) {}

  // Enqueue operation
  void enQueue(int val) {
    if ((rear + 1) % size == front) { // Queue is full
      throw runtime_error("Queue is full");
    } else if (front == -1 && rear == -1) { // First element
      front = rear = 0;
      q[rear] = val;
    } else { // Normal case
      rear = (rear + 1) % size;
      q[rear] = val;
    }
  }

  // Dequeue operation
  int deQueue() {
    if (front == -1) { // Queue is empty
      throw runtime_error("Queue is empty");
    } else if (front == rear) { // Last element
      int temp = q[front];
      front = rear = -1; // Reset to empty state
      return temp;
    } else { // Normal case
      int temp = q[front];
      front = (front + 1) % size;
      return temp;
    }
  }

  // Display queue elements
  void display() const {
    if (front == -1) {
      cout << "Queue is empty" << endl;
      return;
    }
    int i = front;
    while (i != rear) {
      cout << q[i] << " ";
      i = (i + 1) % size;
    }
    cout << q[rear] << endl;
  }

  // Get the current size of the queue
  int currentSize() const {
    if (front == -1)
      return 0;
    return (rear >= front) ? (rear - front + 1) : (size - front + rear + 1);
  }

  // Destructor
  ~Queue() {
    delete[] q;
  }
};

int main() {
  try {
    Queue q(5); // Create a queue of capacity 5

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);

    cout << "Queue elements: ";
    q.display();

    cout << "Dequeuing: " << q.deQueue() << endl;

    cout << "Queue elements after dequeue: ";
    q.display();

    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);

    cout << "Queue elements after enqueuing more: ";
    q.display();

    // Uncommenting this will throw an error (Queue is full)
    // q.enQueue(70);

    cout << "Dequeuing all elements: ";
    while (q.currentSize() > 0) {
      cout << q.deQueue() << " ";
    }
    cout << endl;

    cout << "Queue elements after clearing: ";
    q.display();
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
