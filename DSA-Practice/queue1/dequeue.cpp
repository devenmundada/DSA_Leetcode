#include <iostream>

using namespace std;

class Deque {
private:
  int *arr;
  int n;
  int front;
  int rear;

public:
  Deque(int size) {
    this->n = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void pushFront(int val) {
    if (front == 0) {
      // iss ka matlab mere pas left side mai koi jaga he nhi hai
      // element push karne ke liye toh...overflow kehenge
      cout << "Overflow" << endl;
    } 
    else if (front == -1 && rear == -1) {
      // iska matlab queue phele empty thi..aur mai 1st element insert karne
      // aaya hu !
      front ++;
      rear ++;
      arr[front] = val;
    }
    else{
        // Normal Flow
        front --;
        arr[front] = val; 
    }
  }
  void popBack() {
    if(front == -1 && rear == -1){
        // iss case mai quue already empty hai..toh undeflow ho jayega 
        cout << "Underflow" << endl; 
    }
    else if(front == rear){
        arr[rear] = -1;  //Single Element
        front = -1;
        rear = -1;
    }
    else{ //Normal Case
        arr[rear] = -1;
        rear--;
    }
  }
  void pushBack(int val) {
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
  void popFront() {
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
  void print(){
    for(int i = 0;i<n ;i++){
        cout << arr[i] <<" ";
    }
    cout << endl;
  }
};

int main() {
    Deque q(5);

    q.pushFront(10);
    q.print();    
    q.pushFront(20);
    q.print();
    q.pushBack(30);
    q.print();
    q.pushBack(35);
    q.print();
    // q.popBack();
    // q.print();
    // q.popBack();
    // q.print();
    // q.popBack();
    // q.print();
    // q.popBack();
    // q.print();
    q.popFront();
    q.print();
    q.popFront();
    q.print();

    return 0;
}

