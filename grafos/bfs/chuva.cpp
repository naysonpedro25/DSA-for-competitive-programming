#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int MAXN = 1010;
// https://neps.academy/br/exercise/469
bool visited[MAXN][MAXN];
char t[MAXN][MAXN];

void dfs(int I, int J, int maxI, int maxJ) {

  queue<pair<int, int>> q;
  q.push({I, J});

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    if (i + 1 < maxI && t[i + 1][j] == '.') {
      t[i + 1][j] = 'o';
      q.push({i + 1, j});
    }
    if (j - 1 >= 0 && t[i][j - 1] == '.' && i + 1 < maxI &&
        t[i + 1][j] == '#') {
      t[i][j - 1] = 'o';
      q.push({i, j - 1});
    }
    if (j + 1 < maxJ && t[i][j + 1] == '.' && i + 1 < maxI &&
        t[i + 1][j] == '#') {
      t[i][j + 1] = 'o';
      q.push({i, j + 1});
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  int oi, oj;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t[i][j];
      if (t[i][j] == 'o') {
        oi = i;
        oj = j;
      }
    }
  }

  dfs(oi, oj, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << t[i][j];
    }
    cout << '\n';
  }

  return 0;
}
