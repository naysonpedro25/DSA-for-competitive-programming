#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int pai[MAXN], sz[MAXN];
// https://neps.academy/br/exercise/2162 
int find(int x) {
  if (pai[x] == x)
    return x;
  int r = find(pai[x]);
  pai[x] = r;
  return pai[x];
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

  int n, r, k;
  cin >> n >> r >> k;
  init(n);
  int res = 0;

  for (int i = 0; i < r; i++) {
    int a, b;
    cin >> a >> b;
    join(a, b);
  }

  set<int> st;

  for (int i = 1; i <= n; i++) {
    int p = find(i);
    if (!st.count(p)) {
      res += sz[p] / k;
      if (sz[p] % k > 0)
        res++;
    }
    st.insert(p);
  }
  cout << res;

  return 0;
}
