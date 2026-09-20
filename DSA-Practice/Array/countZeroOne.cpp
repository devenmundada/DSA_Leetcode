#include <iostream>
using namespace std;

void countZeroOne(int arr[], int n) {
  int zeroCount = 0;
  int oneCount = 0;
  // counting
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      zeroCount++;
    }
    if (arr[i] == 1) {
      oneCount++;
    }
  }
  // insertion

fill(arr,arr+zeroCount,0);
fill(arr+zeroCount,arr+n,1);

//   int i = 0;
//   for (; i < zeroCount; i++) {
//     arr[i] = 0;
//   }
//   for (; i < n; i++) {
//     arr[i] = 1;
//   }
}

void printAllPair(int arr[],int n){
    for(int i = 0;i < n;i++){
        for(int j = n-1;j > i ;j--){
            cout << arr[i] << ", " << arr[j] << endl;
        }
    }
}

void rotateArray(int arr[],int size, int n) {
    // n -> here refers to the number by which we have to shif the array
    n = n%size;

    if(n == 0){
        // no need to do anything
        return;
    }
    // step 1: copy last finalShift element into the temp
    int temp[10000];
    int index = 0;
    for(int i = size-n;i < size;i++){
        temp[index] = arr[i];
        index++;
    }
    // step 2: shift array element by the n places
    for(int i = size-1;i >=0;i--){
        if(i - n >= 0){
            arr[i] = arr[i-n];
        }
    }
    // step 3: copy temp elements into the original array
    for(int i = 0;i < n;i++){
        arr[i] = temp[i];
    }

}

int main() {

    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    // cyclically rotate array by 2 places
    int n = 1;

    cout << "Before" << endl;
    for(int i = 0;i < size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    rotateArray(arr,size,n);

    cout << "After" << endl;
    for(int i = 0;i < size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    
    
    // printAllPair(arr, n);

//   int arr[] = {0, 1, 1, 1, 0, 0};
//   int size = 6;

//   countZeroOne(arr, size);
//   for (int i = 0; i < size; i++) {
//     cout << arr[i] << " ";
//   }
}