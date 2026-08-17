#include <bits/stdc++.h>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
const int MAXN = 110;
// https://neps.academy/br/exercise/318
int pai[MAXN], peso[MAXN];

struct Edge {
  int c;
  int x, y;
};

int find(int x) {
  if (pai[x] == x)
    return x;

  pai[x] = find(pai[x]);
  return pai[x];
}

void join(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return;

  if (peso[y] > peso[x])
    swap(x, y);

  pai[y] = x;
  peso[x] += peso[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, f, r;
  cin >> n >> f >> r;
  for (int i = 1; i <= n; i++) {
    pai[i] = i;
    peso[i] = 1;
  }
  vector<Edge> fs(f), rs(r);

  for (int i = 0; i < f; i++) {
    cin >> fs[i].x >> fs[i].y >> fs[i].c;
  }

  for (int i = 0; i < r; i++) {
    cin >> rs[i].x >> rs[i].y >> rs[i].c;
  }

  const auto comp = [](Edge a, Edge b) { return a.c < b.c; };
  sort(fs.begin(), fs.end(), comp);
  sort(rs.begin(), rs.end(), comp);

  int j = 0, res = 0;
  for (int i = 0; i < f; i++) {
    if (find(fs[i].x) != find(fs[i].y)) {
      join(fs[i].x, fs[i].y);
      res += fs[i].c;
    }
  }
  for (int i = 0; i < r; i++) {
    if (find(rs[i].x) != find(rs[i].y)) {
      join(rs[i].x, rs[i].y);
      res += rs[i].c;
    }
  }

  cout << res;

  return 0;
}
