#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
// https://usaco.org/index.php?page=viewproblem2&cpid=572
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);
  int n, q;
  cin >> n >> q;

  vector<int> v(n), p1(n + 1, 0), p2(n + 1, 0), p3(n + 1, 0);

  for (int &i : v)
    cin >> i;

  for (int i = 0; i < n; i++) {
    p1[i + 1] = p1[i];
    p2[i + 1] = p2[i];
    p3[i + 1] = p3[i];

    if (v[i] == 1)
      p1[i + 1] += 1;
    else if (v[i] == 2)
      p2[i + 1] += 1;
    else
      p3[i + 1] += 1;
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << p1[b] - p1[a - 1] << " " << p2[b] - p2[a - 1] << " "
         << p3[b] - p3[a - 1] << '\n';
  }
  return 0;
}
