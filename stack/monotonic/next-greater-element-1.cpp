#include <bits/stdc++.h>
#include <map>
#include <stack>
#include <vector>

using namespace std;
// https://leetcode.com/problems/next-greater-element-i/description/

int main() {

  vector<int> nums1 = {2, 4}, nums2 = {1, 2, 3, 4};

  map<int, int> mp;
  stack<int> ms;
  for (int j = nums2.size() - 1; j >= 0; j--) {
    while (!ms.empty() && nums2[ms.top()] <= nums2[j])
      ms.pop();

    if (ms.empty())
      mp[nums2[j]] = -1;
    else
      mp[nums2[j]] = nums2[ms.top()];

    ms.push(j);
  }

  vector<int> res;

  for (int i : nums1) {
    res.push_back(mp[i]);
    cout << mp[i] << " ";
  }

  return 0;
}
