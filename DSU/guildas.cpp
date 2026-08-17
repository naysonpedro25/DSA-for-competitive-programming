#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
// https://neps.academy/br/exercise/286
const int MAXN = 1e5 + 10;
int pai[MAXN], sz[MAXN], soma[MAXN];

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

  if (sz[x] < sz[y]) {
    swap(x, y);
  }
  pai[y] = x;
  sz[x] += sz[y];
  soma[x] += soma[y];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (1) {
    int n, m;
    cin >> n >> m;
    if (n == 0 && m == 0)
      return 0;

    for (int i = 1; i <= n; i++) {
      cin >> soma[i];
      pai[i] = i;
      sz[i] = 1;
    }
    int res = 0;
    while (m--) {
      int q, a, b;
      cin >> q >> a >> b;

      if (q == 1) {
        join(a, b);
      } else {
        int x = find(a), y = find(b);
        if (x == 1 && soma[x] > soma[y]) {
          res++;
        } else if (y == 1 && soma[y] > soma[x]) {
          res++;
        }
      }
    }

    cout << res;
  }

  return 0;
}