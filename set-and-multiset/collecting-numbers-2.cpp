#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<int> v(n + 1, 0), pos(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    pos[v[i]] = i;
  }
  int res = 1;
  for (int i = 1; i < n; i++) {
    if (pos[i] > pos[i + 1])
      res++;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;

    int x = v[a];
    int y = v[b];

    set<pair<int, int>> st;
    if (x - 1 > 0)
      st.insert({x - 1, x});
    if (x + 1 <= n)
      st.insert({x, x + 1});
    if (y - 1 > 0)
      st.insert({y - 1, y});
    if (y + 1 <= n)
      st.insert({y, y + 1});

    for (auto [x1, x2] : st) {
      if (pos[x1] > pos[x2]) {
        res--;
      }
    }
    swap(pos[x], pos[y]);
    swap(v[a], v[b]);

    for (auto [x1, x2] : st) {
      if (pos[x1] > pos[x2]) {
        res++;
      }
    }
    cout << res << endl;
  }

  return 0;
}

/*

input
5
5 4 2 3 1

4

*/