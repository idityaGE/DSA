#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node *next;
  Node(int val)
      : data(val), next(nullptr) {}
};

class Queue {
  Node *front, *rear;

 public:
  // Constructor
  Queue()
      : front(nullptr), rear(nullptr) {}

  // Destructor
  ~Queue() {
    while (front != nullptr) {
      Node *temp = front;
      front = front->next;
      delete temp;
    }
  }

  // Enqueue an element
  void enqueue(int val) {
    Node *newNode = new Node(val);
    if (rear == nullptr) { // Queue is empty
      front = rear = newNode;
    } else {
      rear->next = newNode;
      rear = newNode;
    }
  }

  // Dequeue an element
  int dequeue() {
    if (front == nullptr) { // Queue is empty
      throw runtime_error("Queue is empty");
    }
    int value = front->data;
    Node *temp = front;
    front = front->next;
    if (front == nullptr) { // Queue becomes empty after dequeue
      rear = nullptr;
    }
    delete temp;
    return value;
  }

  // Display the queue elements
  void displayQueue() const {
    if (front == nullptr) {
      cout << "Queue is empty" << endl;
    } else {
      Node *current = front;
      while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
      }
      cout << endl;
    }
  }
};

int main() {
  try {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Queue: ";
    q.displayQueue();

    cout << q.dequeue() << " dequeued from queue" << endl;
    cout << q.dequeue() << " dequeued from queue" << endl;

    cout << "Queue after dequeuing: ";
    q.displayQueue();
  } catch (const exception &e) {
    cerr << "Error: " << e.what() << endl;
  }

  return 0;
}
