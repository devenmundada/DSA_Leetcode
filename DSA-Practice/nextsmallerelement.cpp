#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void nextsmallersolve(int arr[], int n, vector<int>& ans) {
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--) {
        int element = arr[i];
        while (!s.empty() && s.top() > element) {
            s.pop();
        }
        ans.push_back(s.top());
        s.push(element);
    }
}

void prevsmallerElement(int arr[],int n,vector<int>& ans){
    stack<int>s;
    s.push(-1);

    // difference bas itna hai ki
    for(int i=0;i<n;i++){
        int element = arr[i];
        while(s.top() > element){
            s.pop();
        }
        // if yaha pe aaye hai matlab stack ke top pe koi chota element hai
        ans.push_back(s.top());
        s.push(arr[i]);
    }
}


int main(){
    // input
    int arr[] = {8,4,6,2,3};
    int n = 5;
    vector <int> ans;
    
    // nextsmallersolve(arr,n,ans);

    prevsmallerElement(arr,n,ans);

    // reverse(ans.begin(),ans.end());

    for(auto i:ans){
        cout << i << " ";
    }
    return 0;
}