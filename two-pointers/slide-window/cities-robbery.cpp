#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>
#include <iterator>
#include <utility>
#include <vector>
// https://csacademy.com/contest/archive/task/cities-robbery/
using namespace std;

#define ll long long

int main() {

  ll n, x, k;

  cin >> n >> x >> k;

  vector<ll> posi(n);
  vector<ll> v(n);
  vector<ll> pref(n + 1, 0);

  for (ll i = 0; i < n; i++) {
    cin >> posi[i];
    cin >> v[i];
    pref[i + 1] = pref[i] + v[i];
  }

  ll cust = INT_MAX;

  ll res = 0;

  for (ll r = 0, l = 0; r < n; r++) {

    while (l <= r) {
      cust = min(abs(x - posi[r]) + abs(posi[r] - posi[l]),
                 abs(x - posi[l]) + abs(posi[l] - posi[r]));
      if (cust <= k)
        break;
      l++;
    }

    res = max(res, pref[r + 1] - pref[l]);
  }

  cout << res;
  return 0;
}
