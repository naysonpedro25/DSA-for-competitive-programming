#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1192
vector<vector<char>> mt;
bool v[1001][1001];
int dI[4] = {1, -1, 0, 0}, dJ[4] = {0, 0, 1, -1};

void dfs(int ni, int nj, int n, int m) {
  queue<pair<int, int>> q;
  q.push({ni, nj});
  v[ni][nj] = 1;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {

      int ci = u.first + dI[k], cj = u.second + dJ[k];

      if (ci >= 0 && ci < n && cj >= 0 && cj < m && !v[ci][cj] &&
          mt[ci][cj] == '.') {
        v[ci][cj] = 1;
        q.push({ci, cj});
      }
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;

  mt.resize(n);
  fill(mt.begin(), mt.end(), vector<char>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mt[i][j];
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mt[i][j] == '.' && !v[i][j]) {
        dfs(i, j, n, m);
        res++;
      }
    }
  }

  cout << res;

  return 0;
}
