#include <bits/stdc++.h>
#include <functional>
#include <map>
#include <queue>
#include <utility>
#include <vector>

// https://cses.fi/F/task/1660
// https://cses.fi/problemset/task/1661

#define LL long long
using namespace std;
int main() {
  LL n;
  cin >> n;

  vector<LL> v(n);
  map<LL, LL> mp;
  mp[0] = 1;

  for (LL i = 0; i < n; i++)
    cin >> v[i];

  LL res = 0;
  LL pref = 0;
  for (LL i = 0; i < n; i++) {
    pref += v[i];

    LL mod = pref % n;
    while (mod < 0) {
      mod += n;
    }

    if (mp.count(mod))
      res += mp[mod];

    mp[mod]++;
  }
  

  cout << res;

  return 0;
}