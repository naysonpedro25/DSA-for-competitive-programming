#include <bits/stdc++.h>
// https://leetcode.com/problems/non-overlapping-intervals/submissions/2128808489/
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> intervals = {{1,2},{2,3}};

  sort(intervals.begin(), intervals.end(),
       [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

  int n = intervals.size();
  int count = 1, f =  intervals[0][1];
  for (int i = 1; i < n; i++) {
    if (intervals[i][0] >= f) {
      count++;
      f = intervals[i][1];
    }
  }

  cout << (n - count);
  return 0;
}
