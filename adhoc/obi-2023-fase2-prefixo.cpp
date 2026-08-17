#include <bits/stdc++.h>
using namespace std;
// https://neps.academy/br/exercise/2437
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  string p, s;
  cin >> n >> p >> m >> s;

  int i = 0, res = min(n, m);
  while (i < m && i < n) {
    if (s[i] != p[i]) {
      res = i;
      break;
    }
    i++;
  }

  cout << res;

  return 0;
}
