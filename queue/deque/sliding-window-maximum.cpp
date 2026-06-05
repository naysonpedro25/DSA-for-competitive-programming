#include "bits/stdc++.h"
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main() {

  int k = 1;
  deque<int> dq;
  vector<int> res = {};
  vector<int> nums = {1, -1};
  int n = nums.size();
  for (int i = 0; i < n; i++) {
    while (!dq.empty() && nums[dq.back()] <= nums[i]) {
      dq.pop_back();
    }

    dq.push_back(i);
    if(i - dq.front()  + 1 > k) dq.pop_front();

    if (i >= k -1) {
      res.push_back(nums[dq.front()]);
    }

    
  }

  for (int i : res)
    cout << i << " ";
  return 0;
}