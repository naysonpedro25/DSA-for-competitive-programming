#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://leetcode.com/problems/video-stitching/description/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> v = {{0, 2}, {4, 6}, {8, 10}, {1, 9}, {1, 5}, {5, 9}};
  int t = 10;
  sort(v.begin(), v.end(),
       [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
  int n = v.size();

  int cnt = 0, maxAl = 0, alc = 0, i = 0;
  while (alc < t) {
    while (i < n && alc >= v[i][0]) {
        maxAl = max(maxAl, v[i][1]);
        i++;
    }

    if(alc == maxAl) return -1;
    
    alc = maxAl;
    cnt++;
  }
  

  return 0;
}
