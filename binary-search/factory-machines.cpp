#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  long long l = 0, r = 1e18, mid, res = 0;
  // r tem esse valor pois os limites diz q um máquina pode demorar 10^9
  // segundos e a quantidade total pode ser 10^9 itens, logo esse limite no pior
  // caso com 1 máqiuina
  while (l <= r) {
    mid = (l + r) / 2;
    long long s = 0;

    for (int i = 0; i < n; i++) {
      s += mid / v[i];
      if (s >= t)
        break;
    }

    if (s >= t) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << res;

  return 0;
}
