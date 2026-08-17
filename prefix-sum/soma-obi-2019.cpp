// https://neps.academy/br/exercise/468
#include "bits/stdc++.h"
#include <unordered_map>
#include <vector>

using namespace std;
#define ll long long
int main() {

  ll n, k;
  cin >> n >> k;
  vector<ll> v(n);

  for (ll i = 0; i < n; i++)
    cin >> v[i];

  unordered_map<ll, ll> mp;
  ll pref = 0;
  ll res = 0;
  mp[0] = 1;
  for (ll i = 0; i < n; i++) {
    pref += v[i];

    if (mp.count(pref - k)) {
      res += mp[pref - k];
    }

    mp[pref]++;
  }
  cout << res;
  return 0;
}

