#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// https://neps.academy/br/exercise/1388
const int MAXN = 1e6 + 10;
int pai[MAXN], sz[MAXN];
// vector<set<int>> filhos(MAXN);

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

  //   filhos[x].insert(filhos[y].begin(), filhos[y].end());
  //   filhos[y].clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    pai[i] = i;
    sz[i] = 1;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;

    join(a, b);
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) == find(k)) {
      cout << i << " ";
    }
  }

  return 0;
}
