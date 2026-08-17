
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>

// https://neps.academy/br/exercise/2039

using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    pair<int, int> a;
    cin >> a.first >> a.second;
    v[i] = a;
  }

  sort(v.begin(), v.end());

  int res = 0;
  for (int i = 0; i < n; i++) {
    auto cmp = v[i];

    while (!pq.empty() && cmp.first > pq.top()) {
      pq.pop();
    }

    pq.push(cmp.second);
    res = max(res, (int)pq.size());
  }

  cout << res;
  return 0;
}