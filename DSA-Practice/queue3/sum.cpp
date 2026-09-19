#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int sumofminmaxofallwindowsofsizek(vector<int> &nums, int k) {
  deque<int> dq, dq2;
  int ans = 0;

  // process first window
  for (int i = 0; i < k; i++) {
    int element = nums[i];
    // ye element queue ke andar insert hoga he,but hum ek kaam kar skte hai
    // abhi tak jitni bhi queue bani hai uss mai check karege konsa faltu
    // element hai and unko pop kardo faltu -> current element se chote elements
    // jo hai

    // Chota element remove kardo
    while (!dq.empty() && nums[dq.back()] >= element) {
      dq.pop_back();
    }

    // bada element remove kardo
    while (!dq2.empty() && nums[dq2.back()] <= element) {
      dq2.pop_back();
    }
    // Current element ko toh insert karna he hai !
    dq.push_back(i);
    dq2.push_back(i);
  }

  ans += nums[dq.front()] + nums[dq2.front()];

  // // get answer for 1st window
  // int index = dq.front();
  // int element = nums[index];
  // ans.push_back(element);

  // Process the remaining window
  for (int i = k; i < nums.size(); i++) {
    // Removal
    if (!dq.empty() && dq.front() < i - k + 1) {
      dq.pop_front();
    }
    if (!dq2.empty() && dq2.front() < i - k + 1) {
      dq2.pop_front();
    }
    // Addition
    int element = nums[i];

    while (!dq.empty() && nums[dq.back()] >= element) {
      dq.pop_back();
    }

    while (!dq2.empty() && nums[dq2.back()] <= element) {
      dq2.pop_back();
    }
    // current element toh insert karna he hai !
    dq.push_back(i);
    dq2.push_back(i);

    // // Store ans
    // int index = dq.front();
    // int ansElement = nums[index];
    // ans.push_back(ansElement);

    ans += nums[dq.front()] + nums[dq2.front()];
  }
  return ans;
}

int main() {
  vector<int> v{2, 5, -1, 7, -3, -1, -2};
  int k = 4;
  cout << sumofminmaxofallwindowsofsizek(v, k) << endl;
}