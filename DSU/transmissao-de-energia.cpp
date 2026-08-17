#include <bits/stdc++.h>
using namespace std;
// https://neps.academy/br/exercise/626
const int MAXN = 1e5 + 10;
int pai[MAXN], sz[MAXN], ctn = 0;
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
  ctn--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = 1;
  while (1) {
    int e, l;
    cin >> e >> l;
    if (e == 0 && l == 0)
      return 0;

    for (int i = 1; i <= e; i++) {
      pai[i] = i;
      sz[i] = 1;
    }
    ctn = e;

    while (l--) {
      int x, y;
      cin >> x >> y;
      join(x, y);
    }

    cout << "Teste " << n++ << endl;
    if (ctn > 1) {
      cout << "falha" << endl;
    } else
      cout << "normal" << endl;
  }
  return 0;
}
