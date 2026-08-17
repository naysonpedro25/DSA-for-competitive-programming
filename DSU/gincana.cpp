#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4;
int p[MAXN];
int pCount;
// https://neps.academy/br/exercise/309
int find(int x) {
  if (x == p[x])
    return x;

  return p[x] = find(p[x]);
}
void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y)
    return;
  p[x] = y;
  pCount--;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  pCount = n;

  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  while (m--) {
    int i, j;
    cin >> i >> j;
    join(i, j);
  }
  cout << pCount;

  return 0;
}
