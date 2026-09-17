#include <bits/stdc++.h>
#include <climits>
using namespace std;
const int MAXN = 1e6 + 10;
int pai[MAXN], sz[MAXN], minEL[MAXN], maxEL[MAXN];
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/B
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

  if (sz[x] < sz[y]) {
    swap(x, y);
  }
  pai[y] = x;
  sz[x] += sz[y];
  minEL[x] = min(minEL[x], minEL[y]);
  maxEL[x] = max(maxEL[x], maxEL[y]);
}

void init(int n) {
  for (int i = 1; i <= n; i++) {
    pai[i] = i;
    sz[i] = 1;
    minEL[i] = i;
    maxEL[i] = i;
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
    cin >> q;

    if (q == "union") {
      cin >> a >> b;
      join(a, b);
    } else {
      cin >> a;
      a = find(a);
      cout << minEL[a] << ' ' << maxEL[a] << " " << sz[a] << endl;
    }
    // cout << (find(a) != find(b) ? "NO" : "YES") << '\n';
  }
  return 0;
}
