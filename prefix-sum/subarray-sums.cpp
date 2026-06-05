#include <bits/stdc++.h>
#include <map>
#include <utility>
#include <vector>

// https://cses.fi/problemset/task/1660
// https://cses.fi/problemset/task/1661

#define LL long long
using namespace std;
int main() {
  LL n, k;
  cin >> n >> k;

  vector<LL> v(n);
  vector<LL> pref(n + 1, 0);
  map<LL, LL> mp;

  for (LL i = 0; i < n; i++)
    cin >> v[i];
  for (LL i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + v[i];
  }


  LL res = 0;
  for (LL i = 0; i < n + 1; i++) {
    if (mp.count(pref[i] - k))
      res += mp[pref[i] - k];

    mp[pref[i]]++;
  }

  cout << res;

  return 0;
}