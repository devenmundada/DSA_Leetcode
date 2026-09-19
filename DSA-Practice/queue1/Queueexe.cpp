#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue<int> q;

  // doubly-ended queue
  deque<int> dq;
  // insertion
  dq.push_front(10);
  // 10
  dq.push_front(30);
  // 10 30
  dq.push_front(50);
  // 10 30 50
  dq.push_back(60);
  // 60 10 30 50

  cout << dq.size() << endl;
  cout << dq.empty() << endl;
  cout << dq.front() << endl;
  cout << dq.back() << endl;

  // removal
  dq.pop_front();
  cout << dq.front() << endl;
  dq.pop_back();
  cout << dq.back() <<endl;

  // q.push(10);
  // q.push(20);
  // q.push(30);
  // q.push(40);

  // // front
  // cout << q.front() << endl;

  // // removal
  // q.pop();
  // cout << q.front() << endl;
}