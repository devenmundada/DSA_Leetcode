#include <iostream>
#include "algorithm.h"  ///ALGORITHM_H -> defined now ! 
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    sort(arr,5);
    return 0;
}
 

//  1. Make .o's of all cpp files : "g++ -c a.cpp"
// 2. Link all the .o and make executable : "g++ a.o b.o main.o -o my_program"