#include <functional>
#include<iostream>
#include<queue>
using namespace std;

int main(){

    // Min heap
    priority_queue<int,vector<int>,greater<int> >pq;

    pq.push(10);
    pq.push(5);
    pq.push(15);
    pq.push(30);

    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    // // creation
    // priority_queue<int> pq;
    // // By default - Max heap
    // // insert
    // pq.push(10);
    // pq.push(5);
    // pq.push(15);
    // pq.push(30);

    // // access front element
    // cout << pq.top() << endl;
    
    // // remova;
    // pq.pop();
    // cout << pq.top() << endl;
    // cout << pq.size() << endl;


}