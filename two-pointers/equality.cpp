// https://csacademy.com/contest/archive/task/equality/statement/
#include "bits/stdc++.h"
#include <algorithm>
#include <climits>

#include <vector>

using namespace std;

#define ll long long

const ll MAXN = 1e5 + 10;
ll f[MAXN];

int main() {
  ll n, k;
  cin >> n >> k;

  ll l = LLONG_MAX, r = LLONG_MIN;

  for (ll i = 0; i < n; i++) {
    ll v;
    cin >> v;
    l = min(l, v);
    r = max(r, v);
    f[v]++;
  }

  ll res = 0;

  while (1) {

    if (r - l <= k)
      break;

    ll minCust = min(f[l], f[r]);
    res += minCust;

    f[l] -= minCust;
    f[r] -= minCust;

    f[l + 1] += minCust;
    f[r - 1] += minCust;

    if (f[l] == 0)
      l++;

    if (f[r] == 0)
      r--;
  }

  cout << res;

  return 0;
}
