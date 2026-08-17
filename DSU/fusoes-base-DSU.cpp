#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// https://neps.academy/br/exercise/264
vector<int> parent, weight;

int find(int v) {
  if (parent[v] == v)
    return v;

  return parent[v] = find(parent[v]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return;

  if (weight[x] > weight[y]) {
    parent[y] = x;
  } else if (weight[x] > weight[y]) {
    parent[y] = x;
  } else {
    parent[x] = y;
    weight[y] += 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  parent.resize(n + 1);
  weight.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  while (k--) {
    char q;
    int x, y;
    cin >> q >> x >> y;
    if (q == 'F') {
      join(x, y);
    } else if (q == 'C') {
      if (find(x) == find(y)) {
        cout << "S" << endl;
      } else
        cout << "N" << endl;
    }
  }

  return 0;
}
