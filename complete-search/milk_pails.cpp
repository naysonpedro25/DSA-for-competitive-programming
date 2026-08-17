// https://usaco.org/index.php?page=viewproblem2&cpid=615
#include <bits/stdc++.h>

using namespace std;
int main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m;
  cin >> x >> y >> m;

  int mx = 0;

  for (int i = 0; i * x < m; i++) {
    for (int j = 0; j * y < m; j++) {
      int total = i * x + j * y;
      if (total <= m)
        mx = max(mx, total);
    }
  }

  cout << mx << "\n";
}