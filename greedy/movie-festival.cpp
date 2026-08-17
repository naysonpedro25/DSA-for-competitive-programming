// https://cses.fi/problemset/task/1629
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/result/18188560/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i].second >> v[i].first;
  }
  sort(v.begin(), v.end());
  // priority_queue<int> q;
  int res = 1;
  int l = v[0].first;
  for (int i = 1; i < n; i++) {
    if (v[i].second >= l) {
      l = v[i].first;
      res++;
    }
  }

  cout << res;

  return 0;
}
