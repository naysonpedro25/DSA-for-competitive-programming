#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
// https://codeforces.com/problemset/problem/1133/C

using namespace std;

#define ll long long

int main() {
  ll n;
  cin >> n;

  ll v[n];

  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v, v + n);

  ll l = 0, r = 1;
  ll count = 1;

  while (l < r && r < n) {
    ll dif = v[r] - v[l];

    if (dif <= 5) {
      count = max(count, r - l + 1);
      r++;
    } else {
      l++;
      if (r < n - 1 && l >= r) {
        r++;
      }
    }
  }
  cout << count;
  return 0;
}

// semelhante ao diamond collector 1, a implementação que fiz lá é bem mais limpa que essa