#include <bits/stdc++.h>
#include <functional>
using namespace std;
const int MAXN = 1e6 + 10;
// https://neps.academy/br/exercise/3580
int pai[MAXN], sz[MAXN];

int find(int x) {
  if (pai[x] == x)
    return x;

  return pai[x] = find(pai[x]);
}

bool join(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return false;

  if (sz[x] >= sz[y]) {
    pai[y] = x;
    sz[x] += sz[y];
  } else {
    pai[x] = y;
    sz[y] += sz[x];
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  bool res = 1;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    pai[i] = i;
    sz[i] = 1;
  }
  vector<pair<int, int>> rd;
  while (m--) {
    int a, b, t;
    cin >> a >> b >> t;

    if (t == 1) {
      if (!join(a, b))
        res = false;
    } else {
      rd.push_back({a, b});
    }
  }

  if (!res) {
    cout << (res ? "S" : "N");
    return 0;
  }

  int lim = rd.size() - k,
      count = 0; // lim é o mínimo de rodovias que existia antes de k

  for (auto [a, b] : rd) {
    // só conta as rodovias que não criam cilcos com as hidrovias, ou seja
    // maximo de rodovias que consigo contar sem criar ciclos
    if (join(a, b)) {
      count++;
    }
  }

  if (count < lim) /// se a quantidade de rodovias for menor que o mínimo que tinha no passado
  // ou seja, é impossível ter a quantidade de lim rodovias sem que forme um ciclo
    res = false;

  cout << (res ? "S" : "N");

  return 0;
}
