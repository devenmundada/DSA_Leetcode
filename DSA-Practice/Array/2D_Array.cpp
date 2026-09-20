#include <iostream>
using namespace std;

// bool search2DArray(int arr[][4],int rowSize,int colSize,int target){
//     for(int i = 0;i < rowSize;i++){
//         for(int j = 0;j < colSize;j++){
//             if(arr[i][j] == target){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool search2DArray2(vector<vector<int>>arr,int target){
    int rowSize = arr.size();
    int colSize = arr[0].size();

    for(int i = 0;i < rowSize;i++){
        for(int j = 0;j  <colSize;j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

int findminimumin2DArray(int arr[][4],int rowSize, int colsize){
    int minvalue = INT_MAX;

    for(int i = 0;i < rowSize;i++){
        for(int j = 0;j < colsize;j++){
            minvalue = min(minvalue,arr[i][j]);
        }
    }
    return minvalue;
    // Overall T.C -> O(rowSize * colSize)
    // Overall S.C -> O(1)
}

int main(){

// vector<vector<int>> arr(4,vector<int>(3,0));
// int rowSize = arr.size();
// int colSize = arr[0].size();

  int arr[3][4] = {
      {111, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
  };
  int rowSize = 3;
  int colSize = 4;

  int ans = findminimumin2DArray(arr,rowSize, colSize);
  cout << ans << endl;


//   int target = 100;
//   bool ans = search2DArray(arr,rowSize,colSize,target);
//   cout << "ans is:" << ans << endl;

}