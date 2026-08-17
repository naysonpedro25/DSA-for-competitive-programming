// https://cses.fi/problemset/task/1619
#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    cin >> v[i].second;
  }

  sort(v.begin(), v.end());

  priority_queue<int, vector<int>, greater<int>> q;
  int res = 0;

  for (int i = 0; i < n; i++) {
    while (!q.empty() && v[i].first > q.top())
      q.pop();

    q.push(v[i].second);
    res = max(res, (int)q.size());
  }
  cout << res;

  return 0;
}