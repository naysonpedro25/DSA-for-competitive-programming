#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // https://codeforces.com/problemset/status?my=on
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
      cin >> i;

    int res = 0, i = 0, j = n - 1;
    int pi = v[i];
    int pj = v[j];

    while (i < j) {
      if (pi == pj) {
        res = max(res, n - (j - i - 1));
      }
      if (pi < pj) {
        i++;
        pi += v[i];
      } else {
        j--;
        pj += v[j];
      }
    }
    cout << res << '\n';
  }

  return 0;
}
