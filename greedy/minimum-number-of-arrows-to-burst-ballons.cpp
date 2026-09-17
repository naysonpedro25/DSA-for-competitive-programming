#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  sort(points.begin(), points.end(),
       [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
  int n = points.size();
  int res = 0, e ;
  for (int i = 0; i < n; i++) {
    res++;
    e = points[i][1];
    while (i + 1 < n && e >= points[i +1][0]) {
      i++;
    }
  }

  cout << res;

  return 0;
}
