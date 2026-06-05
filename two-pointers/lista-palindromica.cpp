#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main() {
  // Seu código vai aqui
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  ll l = 0, r = n - 1;
  ll res = 0;
  while (l < r) {
    if (v[l] == v[r]) {
      l++;
      r--;
    } else if (v[l] < v[r]) {

      v[l + 1] += v[l];
      l++;
      res++;
    } else {

      v[r - 1] += v[r];
      r--;
      res++;
    }
  }

  cout << res;
  return 0;
}
//https://neps.academy/br/exercise/1725
