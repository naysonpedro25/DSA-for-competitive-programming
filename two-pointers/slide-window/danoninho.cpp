#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

// https://neps.academy/br/exercise/2281
// maior intervalo com soma <= k

using namespace std;
#define ll long long
int main() {
  ll n, k;

  cin >> n >> k;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll r = 0, l = 0;
  ll res = 0;
  ll soma = 0;
  for (; r < n; r++) {
    soma += v[r];

    while (l <= r && soma > k) {
      soma -= v[l];
      l++;
    }

    res = max(res, r - l + 1);
  }
  cout << res;
  return 0;
}
