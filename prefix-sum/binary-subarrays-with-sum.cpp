// https://leetcode.com/problems/binary-subarrays-with-sum/
#include "bits/stdc++.h"
using namespace std;
int main() {

  vector<int> nums = {0,0,0,0,0};
  int goal = 0;

  map<int, int> mp;

  mp[0] = 1;
  int pref = 0;
  int res = 0;
  for (int i = 0; i < nums.size(); i++) {
    pref += nums[i];

    if (mp.find(pref - goal) != mp.end()) {
        res += mp[pref -goal];
    }

    mp[pref]++;
  }
  cout << res;
  return 0;
}