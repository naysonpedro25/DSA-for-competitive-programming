#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// https://neps.academy/br/exercise/64
#define ll long long
int main() {
  // Seu código vai aqui
  ll n, b;
  cin >> n >> b;
  vector<ll> v(n);

  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end(), [](ll a, ll b) { return a > b; });
  ll res = 0;

  ll r = n - 1, l = 0;

  if (r == l) {
    cout << 1;
    return 0;
  };

  while (l < r) {

    if (v[l] + v[r] <= b) {
      v[l] += v[r];
      r--;
      l++;
    } else {
      l++;
    }
    res++;
  }

  if (l == r)
    res++;

  cout << res;

  return 0;
}
// https://neps.academy/br/exercise/892