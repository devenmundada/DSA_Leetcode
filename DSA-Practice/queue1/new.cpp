#include <iostream>

using namespace std;

class Queue {
private:
  int *arr;
  int n;
  int front;
  int rear;

public:
  Queue(int size) {
    arr = new int[size]; // array ko intialize kar diya
    n = size;
    front = -1;
    rear = -1; // in starting we are considering empty string sor rear and front
               // are taken -1
  }
  void push(int val) {
    if (rear == n - 1) {
      cout << "overflow" << endl;
    } else if (front == -1 && rear == -1) {
      // inserting first element
      rear++;
      front++;
      arr[rear] = val;
    } else {
      // Normal
      rear++;
      arr[rear] = val;
    }
  }
  void pop() {
    if (front == -1 && rear == -1) {
      cout << "Underflow" << endl;
    } else if (front == rear) {
      // Single Element
      arr[rear] = -1;
      front = -1;
      rear = -1;
    } else {
      // normal
      arr[front] = -1;
      front++;
    }
  }
  int getFront() {
    if (front == -1) {
      cout << "Queue is Empty" << endl;
    } else {
      return arr[front];
    }
  }
  int getRear() {}
  int getSize() {
    // Number of elemnts inside the queue
    if (front == -1 && rear == -1) {
      return 0;
    } else
      return rear - front + 1;
  }
  bool isEmpty() {
    if (rear == -1 && front == -1) {
      return true;
    } else {
      return false;
    }
  }
  void print(){
    for(int i = 0;i<n ;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
  }
};

int main() {
  Queue q(5);

  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.print();
//   cout << q.getSize() << endl;
//   q.push(40);
//   q.print();
//   cout << q.getFront() << endl;
//   q.push(100);
//   cout << q.isEmpty() << endl;

  q.pop();
  cout << q.getSize() << endl;
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  cout << q.getSize() << endl;
  q.pop();
}