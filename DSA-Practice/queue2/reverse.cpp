#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int> &q) {
  stack<int> st;
  while (!q.empty()) {
    int element = q.front();
    q.pop();

    st.push(element);
  }
  // Ab saare element stack ke under push ho gye hai
  // Ab stach se jab elements niklange toh reverse mai niklenege

  while (!st.empty()) {
    int element = st.top();
    st.pop();
    q.push(element);
  }
}

void reverseRec(queue<int> &q){
  if(q.empty()){
    return ;
  }
  // 1 case hum solve karenge
  int frontElement  = q.front();
  q.pop();
  // Bakki recursion smbhal lega
  reverseRec(q);
  // Backtrack
  q.push(frontElement);
}

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  

  reverseRec(q);

  // Print all elements of queue
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
}