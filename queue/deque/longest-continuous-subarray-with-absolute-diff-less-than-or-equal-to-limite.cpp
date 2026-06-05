#include "bits/stdc++.h"
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main() {

  int limit = 2;
  vector<int> nums = {2,2,2,4,4,2,5,5,5,5,5,2};
    
  
  deque<int> maxq, minq;
  int n = nums.size();
  int res = 0;

  int l = 0;
  for (int r = 0; r < n; r++) {

    while (!maxq.empty() && nums[maxq.back()] < nums[r]) {
      maxq.pop_back();
    }
    maxq.push_back(r);

    while (!minq.empty() && nums[minq.back()] > nums[r]) {
      minq.pop_back();
    }

    minq.push_back(r);

    int maxLocal = nums[maxq.front()];
    int minLocal = nums[minq.front()];

    while (l <= r && maxLocal - minLocal > limit) {
      if (maxq.front() == l)
        maxq.pop_front();
      if (minq.front() == l)
        minq.pop_front();

      maxLocal = nums[maxq.front()];
      minLocal = nums[minq.front()];
      l++;
    }

    res = max(res, r - l + 1);
  }

  cout << res;

  // for (int i : res)
  //   cout << i << " ";
  return 0;
}