#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://codeforces.com/contest/1808/problem/B
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> c(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> c[i][j];
      }
    }
    long long res = 0;
    for (int i = 0; i < m; i++) {
      vector<int> k;
      for (int j = 0; j < n; j++) {
        k.push_back(c[j][i]);
      }
      sort(k.begin(), k.end());
      for (int l = 0; l < n; l++) {
        res += 1LL * k[l] * (2 * l - n + 1);
      }
    }

    cout << res << endl;
  }

  return 0;
}
