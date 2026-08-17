#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>

using namespace std;

// https://neps.academy/br/exercise/64
#define ll long long
int main() {
  // Seu código vai aqui
  ll an, vn;
  cin >> an >> vn;
  vector<ll> a(an);
  vector<ll> v(vn);

  for (ll i = 0; i < an; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < vn; i++)
    cin >> v[i];

  sort(v.begin(), v.end());
  sort(a.begin(), a.end());

  if (v[vn - 1] < a[an - 1]) {
    auto it = upper_bound(a.begin(), a.end(), v[vn - 1]);
    it--;
    cout << (distance(it, a.end()) - 2);
  } else if (v[vn - 1] > a[an - 1]) {
    auto it = upper_bound(v.begin(), v.end(), a[an - 1]);
    it--;
    cout << (distance(it, v.end()) - 2);
  } else {
    cout << 0;
  }
  return 0;
}
// https://neps.academy/br/exercise/892