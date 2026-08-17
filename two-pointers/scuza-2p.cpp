#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;
// https://codeforces.com/problemset/problem/1742/E
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;

    vector<long long> v(n), res(q);
    vector<pair<long long, long long>> qs(q);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    for (int i = 0; i < q; i++) {
      cin >> qs[i].first;
      qs[i].second = i;
    }

    sort(qs.begin(), qs.end());

    int j = 0;
    long long pref = 0;

    for (int i = 0; i < q; i++) {

      while (j < n && qs[i].first >= v[j]) {
        pref += v[j];
        j++;
      }
      res[qs[i].second] = pref;
    }
    for (long long i : res) {
      cout << i << " ";
    }

    cout << '\n';
  }

  return 0;
}
