// https://neps.academy/br/exercise/2795
#include <bits/stdc++.h>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, q;
  cin >> n >> q;

  vector<int> v(n);
  vector<long long> pref(n + 1, 0);
  for (int &i : v)
    cin >> i;
  for (int i = 0; i < n; i++) {
    pref[i + 1] += pref[i] + v[i];
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    long long res = (pref[b] - pref[a - 1]) * 11LL * (b - a);

    cout << res << '\n';
  }
  return 0;
}
