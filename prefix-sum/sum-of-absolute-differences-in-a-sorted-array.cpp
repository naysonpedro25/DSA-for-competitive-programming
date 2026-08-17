#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 5;
  vector<int> nums = {1, 4, 6, 8, 10}, res(n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    total += nums[i];
  }
  int pref = 0, suf = total;
  for (int i = 0; i < n; i++) {
    pref += nums[i];
    res[i] = (i * nums[i] - pref) + (suf - ((n - 1 - i) * nums[i]));
    suf -= nums[i];
  }

  for (int i : res)
    cout << i << " ";

  return 0;
}
