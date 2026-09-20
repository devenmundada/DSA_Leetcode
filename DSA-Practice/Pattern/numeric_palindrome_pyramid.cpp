#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = n;
    for(int i = 0;i < n; i++){  //row
        int c = 1;
        for(int j=0;j < k;j++){  //column           
            if(j < n-i-1){  //print space
                cout << " ";
            }
            else if (j<=n-1) {  //print number
                cout << c ;
                cout << " ";
                c++; 
            }
            else if (j == n){  //print number
                c = c-2;
                cout << c;
                cout << " ";
                c--;
            }
            else{  //print number
                cout << c;
                cout << " ";
                c--;
            }
        }
        k++;  //increment the column count    //for next row count     
        cout << endl;
    }
}
