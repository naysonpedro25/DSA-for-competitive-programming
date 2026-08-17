#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
// https://codeforces.com/contest/863/problem/B
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> v(n * 2);
  for (int &i : v) {
    cin >> i;
  }
  sort(v.begin(), v.end());
  int res = INT_MAX;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      vector<int> r;
      for (int k = 0; k < 2 * n; k++) {
        if (k == i || k == j)
          continue;
        r.push_back(v[k]);
      }

      int minW = 0;
      for (int k = 0; k < 2 * n - 2; k += 2) {
        minW += r[k + 1] - r[k];
      }

      res = min(res, minW);
    }
  }

  cout << res;

  return 0;
}
