#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/2259/my
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;cin >> n;
    vector<int> v(n);
    for (int &i : v)
      cin >> i;
    int imp = 0, par1 = 0, par2 = 0;
    for (int i : v) {
      if (i % 2 != 0) {
        imp++;
      } else if (i % 4 == 0) {
        par2++;
      } else
        par1++;
    }
    cout << max(imp, max(par1, par2)) << '\n';
  }

  return 0;
}
