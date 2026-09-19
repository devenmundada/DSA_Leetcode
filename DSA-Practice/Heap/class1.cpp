#include <iostream>
using namespace std;

class Heap{

public:
    int* arr;
    int capacity;
    int index;

    Heap(int n){
        this->capacity = n;
        arr = new int[n];
        index = 0 ;
        // Jab bhi muje insert karna hoga tab mai index +1 kar ke insert kardunga
    }

    void printHeap(){
        for(int i=0;i<capacity;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void insertHeap(int val){
        if(index == capacity-1){
            cout << "Heap is Full" << endl;
            return;
        }
        // agar jaga hai toh
        index++;
        arr[index] = val;
        // Now put the value in its right posititon
        // by comparing it with parent Node
        int i = index;
        while(i > 1){
            int parentIndex = i/2;

            if(arr[parentIndex] < arr[i]){
                swap(arr[parentIndex],arr[i]);
                i = parentIndex;
            }
            else{
                break;
            }
        }
    }
    
    void deletefromHeap(){
        // Replacement
        swap(arr[1],arr[index]);
        // Size decrease
        index--;
        // Heapify
        // heapify(arr,index,1);
    }

};

void heapify(int *arr,int n,int currIndex){
    // n - no. of elements in heap
    int i = currIndex;
    int leftIndex = 2*i;
    int rightIndex = 2*i+1;
    int largestkaIndex = i;
    // Assuming i par he sab se badi value hai
    // Par left mai hai ya right mai

    // Check for left
    if(leftIndex < n && arr[leftIndex] > arr[largestkaIndex]){
        // left mai badi value mil gayi
        largestkaIndex = leftIndex;
    }
    // check for right
    if(rightIndex < n && arr[rightIndex] > arr[largestkaIndex]){
        // right mai badi value mil gayi
        largestkaIndex = rightIndex;
    }
    if(largestkaIndex != i){
        // left ya right mai se koi 
        swap(arr[i],arr[largestkaIndex]);

        i = largestkaIndex;
        // baaki recursion sambhal lega
        heapify(arr,n,i);
    }
}

void buildHeap(int* arr,int n){
    for(int i = n/2;i>0;i--){
        heapify(arr,n,i);
    }
}

void HeapSort(int* arr,int n){
    // n -> size
    int e = n-1;
    while(e > 1){
        // Delete root element, swap root element with last element
        swap(arr[1],arr[e]);
        // delete last element
        e--;
        // heapify 1 index vala element
        heapify(arr,e+1,1);
    }
}

int main(){

// Heap p(10);

    // 50 40 20 10 30
    int arr[] = {-1,10,20,30,40,50};
    int n = 6;

    buildHeap(arr,n);
    cout << endl;
    for(int i=1;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

// p.insertHeap(10);
// p.printHeap();
// p.insertHeap(20);
// p.printHeap();
// p.insertHeap(30);
// p.printHeap();
// p.insertHeap(40);
// p.printHeap();
// p.insertHeap(50);
// p.printHeap();

// p.deletefromHeap();
// p.printHeap();


}