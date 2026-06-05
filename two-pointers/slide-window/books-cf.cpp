#include <bits/stdc++.h>

using namespace std;
// https://codeforces.com/contest/279/problem/B

int main() {

  int n, t;
  cin >> n >> t;

  vector<int> v(n);
  int res = INT_MIN;

  for (int i = 0; i < n; i++)
    cin >> v[i];
  int soma = 0;
  for (int l = 0, r = 0; r < n; r++) {
    soma += v[r];

    while (soma > t && l <= r) {
      soma -= v[l];
      l++;
    }

    res = max(res, r - l + 1);
  }
  cout << res;

  return 0;
}
