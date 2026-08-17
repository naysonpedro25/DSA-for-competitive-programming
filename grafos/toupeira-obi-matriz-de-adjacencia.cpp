#include "bits/stdc++.h"
#include <vector>

using namespace std;
// https://neps.academy/br/exercise/2323
// matriz de adjacência

#define ll long long
int main() {

  ll s, t;
  cin >> s >> t;

  vector<vector<ll>> g(s, vector<ll>(s, 0));

  for (ll i = 0; i < t; i++) {
    ll x, y;
    cin >> x >> y;
    x--;
    y--;
    g[x][y] = 1LL;
    g[y][x] = 1LL;
  }

  ll p, res = 0;
  cin >> p;

  while (p--) {
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (ll i = 0; i < n; i++) {
      cin >> v[i];
      v[i]--;
    }

    bool isValid = true;
    for (ll i = 0; i < n - 1; i++) {
      if (g[v[i]][v[i + 1]] == 0) {
        isValid = false;
        break;
      }
    }

    if (isValid)
      res++;
  }

  cout << res;

  return 0;
}
