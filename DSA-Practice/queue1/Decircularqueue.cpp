#include <iostream>

using namespace std;

class Decircularqueue {
public:
  int *arr;
  int n;
  int front;
  int rear;

  Decircularqueue(int size) {
    this->n = size;
    arr = new int[size]; // array ko intialize kar diya
    front = -1;
    rear = -1; // in starting we are considering empty string sor rear and front
               // are taken -1
  }

  void pushFront(int val) {
    // 4 cases : Overflow, firstElement, Circular nature, normal flow
    // OverFlow wala
    if (front == 0 && rear == n - 1 || (rear == front - 1)) {
      cout << "Overflow" << endl;
    }
    // First Element
    else if (front == -1 && rear == -1) {
      front++;
      rear++;
      arr[rear] = val;
    }
    // Circular nature
    else if (front == 0 && rear != n - 1) {
      front = n - 1;
      arr[front] = val;
    } else {
      // Normal case
      front--;
      arr[front] = val;
    }
  }
  void pushBack(int val) {
    // 4 cases : Overflow, firstElement, Circular nature, normal flow
    // OverFlow wala
    if (front == 0 && rear == n - 1 || (rear == front - 1)) {
      cout << "Overflow" << endl;
    }
    // First Element
    else if (front == -1 && rear == -1) {
      front++;
      rear++;
      arr[rear] = val;
    }
    // Circular nature
    else if (rear == n - 1 && front != 0) {
      rear = 0;
      arr[rear] = val;
    } else {
      // Normal Flow
      rear++;
      arr[rear] = val;
    }
  }
  void popFront() {
    // 4 cases : Overflow, firstElement, Circular nature, normal flow
    if (front == -1 && rear == -1) {
      cout << "Underflow" << endl;
    } else if (front == rear) {
      // Single element
      arr[front] = -1;
      front = -1;
      rear = -1;
    } else if (front == n - 1) {
      // Circular Nature
      arr[front] = -1;
      front = 0;
    } else {
      // Normal Case
      arr[front] = -1;
      front++;
    }
  }
  void popBack() {
    // 4 cases : Overflow, firstElement, Circular nature, normal flow
    if (front == -1 && rear == -1) {
      cout << "Underflow" << endl;
    } else if (front == rear) {
      // Single element
      arr[front] = -1;
      front = -1;
      rear = -1;
    } else if (rear == 0) {
      // Circular Nature
      arr[rear] = -1;
      rear = n - 1;
    } else {
      // Normal
      arr[rear] = -1;
      rear--;
    }
  }
  void print() {
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {

  Decircularqueue q(5);

  q.pushFront(10);
  q.print();
  q.pushFront(20);
  q.print();
  q.pushBack(30);
  q.print();
  q.pushBack(40);
  q.print();
  q.pushBack(50);
  q.print();
  q.pushFront(60);
  q.print();

  q.popFront();
  q.print();
  q.popFront();
  q.print();

  return 0;
}