#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int pai[MAXN], sz[MAXN];
// https://neps.academy/br/exercise/2436
int find(int x) {
  if (pai[x] == x)
    return x;
  return pai[x] = find(pai[x]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;

  if (sz[y] > sz[x]) {
    swap(x, y);
  }
  pai[y] = x;
  sz[x] += sz[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int e, m, d;
  cin >> e >> m >> d;
  for (int i = 0; i < e; i++) {
    pai[i] = i;
    sz[i] = 1;
  }

  vector<pair<int, int>> ms(m), ds(d);
  for (int i = 0; i < m; i++) {
    cin >> ms[i].first >> ms[i].second;
  }
  for (int i = 0; i < d; i++) {
    cin >> ds[i].first >> ds[i].second;
  }

  for (int i = 0; i < e / 3; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    join(a, b);
    join(a, c);
  }

  int res = 0;

  for (auto [a, b] : ms) {
    if (find(a) != find(b))
      res++;
  }
  for (auto [a, b] : ds) {
    if (find(a) == find(b))
      res++;
  }

  cout << res;

  return 0;
}
