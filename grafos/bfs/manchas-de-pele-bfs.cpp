#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int MAXN = 1010;

bool visited[MAXN][MAXN];
int t[MAXN][MAXN];
// https://neps.academy/br/exercise/567
int dI[4] = {1, -1, 0, 0}, dJ[4] = {0, 0, 1, -1};

void dfs(int I, int J, int maxI, int maxJ) {

  queue<pair<int, int>> q;
  q.push({I, J});

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      int vI = i + dI[k];
      int vJ = j + dJ[k];

      if (vI >= 0 && vI < maxI && vJ >= 0 && vJ < maxJ) {
        if (!visited[vI][vJ] && t[vI][vJ] == 1) {
          visited[vI][vJ] = 1;
          q.push({vI, vJ});
        }
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> t[i][j];
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!visited[i][j] && t[i][j] == 1) {
        dfs(i, j, n, m);
        count++;
      }
    }
  }

  cout << count;

  return 0;
}
