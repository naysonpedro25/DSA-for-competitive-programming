#include <bits/stdc++.h>
using namespace std;
// https://neps.academy/br/exercise/391
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    if (v[i] <= m) {
      res += m - v[i];
      v[i + 1] += m - v[i];
    } else {
      res += v[i] - m;
      v[i + 1] -= v[i] - m;
    }
  }

  cout << res;

  return 0;
}
