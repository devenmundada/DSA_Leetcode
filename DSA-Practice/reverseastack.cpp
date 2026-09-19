#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int val) {
    if (s.empty()) {
        s.push(val);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertAtBottom(s, val);
    s.push(topElement);
}

void reverseStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }

    int topElement = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, topElement);
}

void printStack(stack<int> s) { // pass by value to preserve original
    while (!s.empty()) {
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

    cout << "Original stack: ";
    printStack(s);  // This won't empty original stack now

    reverseStack(s);

    cout << "Reversed stack: ";
    printStack(s);

    return 0;
}
