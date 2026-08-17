#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// https://cses.fi/problemset/task/1193
vector<vector<char>> t;
bool vis[1000][1000];
vector<char> pathDirs;
pair<int, int> parent[1000][1000];
char moves[1000][1000];

int dI[] = {1, -1, 0, 0}, dJ[] = {0, 0, 1, -1};
int pathLanght = 0;
char pathLetter(int x, int y) {
  if (x == 0) {
    if (y == 1) {
      return 'R';
    } else
      return 'L';
  } else {
    if (x == 1)
      return 'D';
    else
      return 'U';
  }
}

bool dfs(int x, int y, int n, int m) {
  vis[x][y] = 1;

  queue<pair<int, int>> q;
  q.push({x, y});

  if (t[x][y] == 'B')
    return true;
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int k = 0; k < 4; k++) {
      int vi = i + dI[k];
      int vj = j + dJ[k];

      if (vi >= 0 && vi < n && vj >= 0 && vj < m && !vis[vi][vj] &&
          (t[vi][vj] == '.' || t[vi][vj] == 'B')) {

        parent[vi][vj] = {i, j};
        moves[vi][vj] = pathLetter(dI[k], dJ[k]);
        vis[vi][vj] = 1;
        q.push({vi, vj});
        if (t[vi][vj] == 'B') {

          while (vi != x || vj != y) {
            pathLanght++;
            pathDirs.push_back(moves[vi][vj]);

            auto [pi, pj] = parent[vi][vj];
            vi = pi;
            vj = pj;
          }

          return true;
        }
      }
    }
  }
  return false;
}

int main() {
  int n, m;

  cin >> n >> m;

  t.resize(n, vector<char>(m));
  int iniI = 0, iniJ = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t[i][j];
      if (t[i][j] == 'A') {
        iniI = i;
        iniJ = j;
      }
    }
  }

  int isValid = dfs(iniI, iniJ, n, m);

  cout << (isValid ? "YES" : "NO") << '\n';
  if (isValid) {
    cout << pathLanght << '\n';
    reverse(pathDirs.begin(), pathDirs.end());
    for (char i : pathDirs) {
      cout << i;
    }
  }

  return 0;
}
