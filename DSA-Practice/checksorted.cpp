#include <iostream>
#include <stack>
using namespace std;

bool checkSorted(stack<int> s,int element1){
    // base case
    if(s.empty()){
        // iska matlab ki stack pura compare ho chuka hai, and sorted hai
        return true;
    }
    // 1 case solve karna hai
    int element2 = s.top();
    s.pop();
    if(element2 < element1){
        // iska matalb ab aage check kar sakte hai
        bool ans = checkSorted(s,element2);
        return ans;
    }
    else{
        return false;
    }
    // backtracking
    s.push(element2);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    int element1 = INT_MAX;
    cout << checkSorted(s,element1) << endl;
    return 0;
    }