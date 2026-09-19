#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int val) {

  // base case
  if (s.empty()) {
    s.push(val);
    return;
  }
  if (!s.empty() && s.top() < val) {
    s.push(val);
    return;
  }
  // 1 case
  int topE = s.top();
  s.pop();
  // baki recursion
  sortedInsert(s, val);
  // Wapas
  s.push(topE);
}
    void print(stack<int> s){
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }


int main() {
  stack<int> s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  int val = 23;

  cout << "Stack Before insertion: ";
  print(s);

  sortedInsert(s, val);

  cout << "Stack after Insertion: ";
  print(s);

  return 0;
}
