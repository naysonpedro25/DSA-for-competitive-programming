
#include <bits/stdc++.h>
// https://usaco.org/index.php?page=viewproblem2&cpid=639

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

  ll count = 1;

  for (ll l = 0, r = 0; r < n; r++) {
    while (v[r] - v[l] > k && l < r) {
      l++;
    }

    count = max(count, r - l + 1);
  }
  cout << count;
  return 0;
}