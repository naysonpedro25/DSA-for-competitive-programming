
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
//https://usaco.org/index.php?page=viewproblem2&cpid=643

using namespace std;

#define ll long long

int main() {

  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  ll n, k;
  cin >> n >> k;

  ll v[n];

  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v, v + n);

  // ll count = 1;

  vector<ll> count(n, 1);

  for (ll l = 0, r = 0; l < n; l++) {
    while (r < n - 1 && v[r + 1] - v[l] <= k) {
      r++;
    }
    count[l] = max(count[l], r - l + 1);
  }

  vector<ll> suf(n);

  for (ll i = n - 2; i >= 0; i--) {
    suf[i] = max(suf[i + 1], count[i]);
  }

  ll res = 0;
  for (ll i = 0; i < n; i++) {
    ll j = i + count[i];

    if (j < n)
      res = max(res, count[i] + suf[j]);
  }

  cout << res;

  return 0;
}

// Questão de filho da puta, quem fez era filho de mãe puta ou pai viado