#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int c, n;
  cin >> c >> n;
  // https://neps.academy/br/exercise/273
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
  }
  priority_queue<int, vector<int>, greater<>> q;
  for (int i = 0; i < c; i++) {
    q.push(v[i].second + v[i].first);
  }
  int res = 0;

  for (int i = c; i < n; i++) {
    int t = -1;
    if (!q.empty()) {
      t = q.top();
      q.pop();
    }

    int ini = max(t, v[i].first);
    int end = ini + v[i].second;
    if (ini - v[i].first > 20)
      res++;
    q.push(end);
  }

  cout << res;

  return 0;
}
