#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//https://leetcode.com/problems/jump-game-ii/description/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  vector<int> nums = {0};
  n = nums.size();

  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    v[i].first = i;
    v[i].second = i + nums[i];
  }

  int maxAcl = 0, alc = 0, i = 0, cnt = 0;

  while (alc < n-1) {
    while (i < n && v[i].first <= alc) {
      maxAcl = max(maxAcl, v[i].second);
      i++;
    }

    if (maxAcl == alc) {
      cout << -1;
      return -1;
    }
    alc = maxAcl;
    cnt++;
  }
  cout << cnt;

  return 0;
}
