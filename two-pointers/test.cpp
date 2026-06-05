#include <bits/stdc++.h>
#include <climits>
#include <deque>

using namespace std;
// https://codeforces.com/contest/279/problem/B

int main() {

  // vector<int> nums = {1, 5, 6, 7, 8, 10, 6, 5, 6};
  vector<int> nums = {8, 2, 4, 7};
  int res = -1;

  int n = nums.size(), limit = 4;

  deque<int> minq, maxq;

  for (int i = 0; i < n; i++) {

    while (!minq.empty() && nums[minq.back()] > nums[i])
      minq.pop_back();
    minq.push_back(i);

    while (!maxq.empty() && nums[maxq.back()] < nums[i])
      maxq.pop_back();
    maxq.push_back(i);


    
    res = max(res, maxq.front() - minq.front());
  }
  cout << res;

  return 0;
}
