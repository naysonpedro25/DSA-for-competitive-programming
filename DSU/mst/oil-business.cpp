#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

const int MAXM = 1e6 + 10;
const int MAXN = 1e6;

struct edge {
  int id;
  long long w;
  int x, y;
};
edge v[MAXM];
int pai[MAXN], sz[MAXN];

int find(int x) {
  if (x == pai[x])
    return x;
  pai[x] = find(pai[x]);
  return pai[x];
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

void init(int n) {
  for (int i = 1; i <= n; i++) {
    pai[i] = i;
    sz[i] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  long long s;
  cin >> n >> m >> s;
  init(n);
  for (int i = 1; i <= m; i++) {
    v[i].id = i;
    cin >> v[i].x >> v[i].y >> v[i].w;
  }

  sort(v + 1, v + 1 + m, [](edge a, edge b) { return a.w > b.w; });
   long long sum = 0;
  vector<int> res;
  vector<edge> rest;
  for (int i = 1; i <= m; i++) {
    edge a = v[i];
    if (find(a.x) != find(a.y)) {
      join(a.x, a.y);
    } else {
      rest.push_back(a);
    }
  }
  sort(rest.begin(), rest.end(), [](edge a, edge b) { return a.w < b.w; });
  for (edge e : rest) {
    if (sum + e.w <= s) {
      sum += e.w;
      res.push_back(e.id);
    }
  }

  cout << res.size() << '\n';
  sort(res.begin(), res.end());
  for (int i : res)
    cout << i << " ";

  return 0;
}
