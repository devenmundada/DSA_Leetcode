#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

string FirstNonRepeating(string A) {
  unordered_map<char, int> freq;
  string ans = "";
  queue<char> q;

  for (int i = 0; i < A.length(); i++) {
    char ch = A[i];
    freq[ch]++;
    // intial state maintain karna hai
    q.push(ch);
    // lets find the answer now
    while (!q.empty()) {
      char frontElement = q.front();
      // Check whether front element is answer or not

      if (freq[frontElement] == 1) {
        ans.push_back(frontElement);
        break;
      } else {
        // front lement is duplicate element
        q.pop();
      }
    }
    // important condition->agar sab element duplicate hai toh q empty hogi
    // agar koi bhi unique element hai toh q empty nhi hogi
    if (q.empty()) {
      ans.push_back('#');
    }
  }
  return ans;
}

int main() {
  string input = "aabadabbajabba";
  cout << FirstNonRepeating(input) << endl;
  return 0;
}