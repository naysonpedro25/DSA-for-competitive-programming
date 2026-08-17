// https://cses.fi/problemset/task/1646
#include "bits/stdc++.h"
#include <vector>

using namespace std;

#define LL long long

int main() {
  LL n, q;
  cin >> n >> q;
  vector<LL> v(n);
  vector<LL> pref(n + 1, 0);

  for (LL i = 0; i < n; i++) {
    cin >> v[i];
    pref[i + 1] = pref[i] + v[i];
  }

  while (q--) {
    LL i, j;
    cin >> i >> j;

    cout << pref[j] - pref[i - 1] << endl;
  }

  return 0;
}
