#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
using namespace std;
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
const int MAXN = 1e6 + 10;
int pai[MAXN], sz[MAXN], xp[MAXN];

int find(int x) {
  if (pai[x] == x)
    return x;

  int r = find(pai[x]);
  if (r != pai[x]) { // se o filho já não é ligado direto no pia, se for eu n
                     // faço nada (pois a dif já é relativa ao pai)
    // nesse caso, com esse if, o filho pega o xp do pai apenas uma vez
    xp[x] += xp[pai[x]];
    pai[x] = r;
  }

  return pai[x];
}
void add(int x, int v) {
  int r = find(x);
  xp[r] += v;
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
  xp[y] -= xp[x];
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
    cin >> q;

    if (q == "join") {
      int x, y;
      cin >> x >> y;
      join(x, y);
    } else if (q == "add") {
      int x, v;
      cin >> x >> v;
      add(x, v);
    } else {
      int x;
      cin >> x;
      int r = find(x);
      cout << (r == x ? xp[x] : xp[r] + xp[x]) << '\n';
    }
  }
  return 0;
}
