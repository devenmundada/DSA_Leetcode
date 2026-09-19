#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> printFirstNegativeinteger(long long A[],long long int N,long long int k){
    deque<long long int> q;
    vector<long long> ans;
    // index store karege hum queue ke ander
    // vo hume bata dega ki current element window mai hai ki nhi

    // Step 1: Pro<cess first Window
    for(int i = 0;i < k;i++){
        int element = A[i];

        if(element < 0){
            q.push_back(i);
        }
    }
    // Store answer for 1st Window
    if(q.empty()){
        ans.push_back(0);
    }
    else{
        int index = q.front();
        int element = A[index];
        ans.push_back(element);
    }

    // Above Window Stores the index's of all the -ve numbers inside the fisrt window

    // Step 2: Process the Remaining window -> ans/removal/addition

    for(int i=k;i<N;i++){

        // Step B: Removal of elemnets Which are not inside the current window
        if(!q.empty() && q.front() < i-k+1){
            q.pop_front();
        }
        // Step c -> Addition of new Element
        int element = A[i];
        if(element < 0){
            q.push_back(i);
        }
        // Step A -> ans store kar rhe purani window ka
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            int index = q.front();
            int element = A[index];
            ans.push_back(element);
        }
    }
    return ans;
}

int main(){
    long long A[] = {-8,2,3,-6,10};
    long long int N = 5;
    long long int k = 2;

    vector<long long> result = printFirstNegativeinteger(A,N,k);
    
        for(auto x : result){
            cout << x << " ";
        }
        cout << endl;
        return 0;
}