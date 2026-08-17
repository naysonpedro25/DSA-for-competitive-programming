#include <bits/stdc++.h>
#include <vector>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);

  for (int &i : v)
    cin >> i;

  map<int, int> ms;

  for (int i = 0; i < n; i++) {
    ms[v[i]] += 1;
  }

  long long res = 1;

  for (auto [k, v] : ms) {
    res = (res * (v + 1)) % MOD;
  }

  res--;

  cout << res;

  return 0;
}
