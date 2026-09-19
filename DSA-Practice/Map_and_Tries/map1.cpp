#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
  // Creation
  unordered_map<int, string> uMap;
  map<int, string> oMap;

  // Insertion
  // insertion using []
  uMap[2] = "Scorpio";
  uMap[1] = "Carens";
  uMap[3] = "Fortuner";

  oMap[2] = "Scorpio";
  oMap[1] = "Carens";
  oMap[3] = "Fortuner";

  cout << "Printing Ordered Map" << endl;

  for (auto i : oMap) {
    cout << i.first << "->" << i.second << endl;
  }
  cout << endl << "Printing unordered Map" << endl;
  for (auto i : uMap) {
    cout << i.first << "->" << i.second << endl;
  }


  // Search or found
  // two methods
  // 1.using count 

  // if(uMap.count(3) == 0){
  //   cout<< endl << "3 Nahi mila" << endl;
  // }
  // else{
  //   cout<< endl << "3 mil gaya" << endl;
  // }

  // 2. using find()
  if(uMap.find(1) == uMap.end()){
    cout << endl << " 1 Nahi mila" << endl;
  }
  else{
    cout << endl << "1 Mil gaya" << endl;
  }

  return 0;
}