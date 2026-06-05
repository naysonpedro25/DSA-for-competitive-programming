#include "bits/stdc++.h"

using namespace std;
class RecentCounter {
  // https://leetcode.com/problems/number-of-recent-calls/description/
public:
  queue<int> mq;
  RecentCounter() {}

  int ping(int t) {
    if (t <= 0)
      return 0;

    while (!mq.empty() && mq.front() < t - 3000)
      mq.pop();
    mq.push(t);

    return mq.size();
  }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */