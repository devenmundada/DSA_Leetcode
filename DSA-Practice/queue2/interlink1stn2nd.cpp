#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> rearrangeQueue(queue<int> &q1){
    vector<int> ans;
    queue<int> q2;

    int n = q1.size();
    int half = n/2;

    while(half--){
        int element = q1.front();
        q1.pop();

        q2.push(element);
    }
    // first half -> q2
    // second half  -> q1;
    int size = q1.size();
    while(size--){
        ans.push_back(q2.front());
        q2.pop();
        ans.push_back(q1.front());
        q1.pop();
    }
    return ans;
}

int main(){
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);

    vector<int> result  = rearrangeQueue(q1);

    for(int x:result){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}