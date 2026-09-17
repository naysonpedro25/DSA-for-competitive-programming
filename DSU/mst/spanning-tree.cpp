#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
const int MAXN = 1e6 + 10;
int pai[MAXN], sz[MAXN];

struct edge {
  int dist;
  int x, y;
};

edge edges[MAXN], mst[MAXN];

int find(int x) {
  if (x == pai[x])
    return x;

  return pai[x] = find(pai[x]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return;

  if (sz[x] < sz[y]) {
    swap(x, y);
  }

  pai[y] = x;
  sz[x] += sz[y];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    pai[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    cin >> edges[i].x >> edges[i].y >> edges[i].dist;
  }
  sort(edges, edges + m, [](edge a, edge b) { return a.dist < b.dist; });
  int j = 0;
  long long res = 0;
  for (int i = 0; i < m; i++) {
    if (find(edges[i].x) != find(edges[i].y)) {
      join(edges[i].x, edges[i].y);
      res += edges[i].dist;
    }
  }

  cout << res;
  return 0;
}
