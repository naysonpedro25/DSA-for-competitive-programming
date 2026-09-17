#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int pai[MAXN], sz[MAXN];

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

  if (sz[x] >= sz[y]) {
    pai[y] = x;
    sz[x] += sz[y];
  } else {
    pai[x] = y;
    sz[y] += sz[x];
  }
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
  cin >> n >> m;
  init(n);
  while (m--) {
    string q;
    int a, b;
    cin >> q >> a >> b;

    if (q == "union")
      join(a, b);
    else
      cout << (find(a) != find(b) ? "NO" : "YES") << '\n';
  }
  return 0;
}
