#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    vector<long long> v(n), prefMax(n + 1, 0), pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + v[i];
      prefMax[i + 1] = max(prefMax[i], v[i]);
      
    }

    while (q--) {
      long long qr;
      cin >> qr;
      auto it = upper_bound(prefMax.begin(), prefMax.end(), qr);
      if (it != pref.begin())
        it--;
      cout << pref[distance(prefMax.begin(), it)] << " ";
    }
    cout << '\n';
  }
  return 0;
}







