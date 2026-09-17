#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://leetcode.com/problems/merge-intervals/description/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> v = {{1, 4}, {2, 3}};
  sort(v.begin(), v.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
  vector<vector<int>> res;

  int n = v.size();
  for (int i = 0; i < n; i++) {
    vector<int> e = v[i];

    while (i + 1 < n && v[i + 1][0] <= e[1]) {
      i++;
      e[1] = max(v[i][1], e[1]);
    }
    res.push_back(e);
  }
  for (auto i : res) {
    cout << i[0] << ' ' << i[1];
  }
  return 0;
}
