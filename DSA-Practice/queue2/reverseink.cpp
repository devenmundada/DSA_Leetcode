#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseinKgroup(queue<int> &q,int k,int count){
    // Base Case
    if(count >= k){
        // toh pakka reverse karna hai
        stack <int> st;
        // Fetch k elements from queue and push them into stack
        for(int i=0;i < k;i++){
            int element = q.front();
            q.pop();

            st.push(element);
        }
        // Now fetch k elements from stack and push them in queue
        for(int i=0;i < k;i++){
            int element = st.top();
            st.pop();

            q.push(element);
        }
        // bakki recusrsion ssambhal lega
        reverseinKgroup(q,k,count - k);
    }
    else{
        // if count < k then jo bache elements hai unhe
        // vaise he queue ke end mai push karna hai
        for(int i = 0;i < count; i++){
            int element  = q.front();
            q.pop();

            q.push(element);
        }
    }
}

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);

    int k = 3;
    int count = q.size();
    // count -> it tracks the number of elemnts to be revrse

    reverseinKgroup(q,k,count);
    // Printing
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
