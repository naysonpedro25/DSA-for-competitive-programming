#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
using namespace std;
// https://usaco.org/index.php?page=viewproblem2&cpid=895
char mt[1010][1010];
bool vis[1010][1010];
int dI[] = {1, -1, 0, 0}, dJ[] = {0, 0, 1, -1};
pair<int, int> dfs(int mi, int mj, int n) {
  vis[mi][mj] = true;

  int cnt = 1;
  int p = 0;

  for (int k = 0; k < 4; k++) {
    int i = mi + dI[k];
    int j = mj + dJ[k];

    if (i < 0 || i >= n || j < 0 || j >= n || mt[i][j] == '.') {
      p++;
    }

    if (i >= 0 && i < n && j >= 0 && j < n && !vis[i][j] && mt[i][j] == '#') {
      auto s = dfs(i, j, n);
      cnt += s.first;
      p += s.second;
    }
  }
  return {cnt, p};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mt[i][j];
    }
  }
  typedef pair<int, int> pii;
  priority_queue<pii, vector<pii>, greater<>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mt[i][j] == '#' && !vis[i][j]) {
        auto [cnt, per] = dfs(i, j, n);
        q.push({-cnt, per});
      }
    }
  }

  cout << -q.top().first << " " << q.top().second;

  return 0;
}
