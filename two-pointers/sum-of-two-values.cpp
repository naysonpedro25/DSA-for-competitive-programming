// https://cses.fi/problemset/task/1640
#include "bits/stdc++.h"
#include <algorithm>

using namespace std;

int main() {

  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> v(n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }

  sort(v.begin(), v.end());

  for (int l = 0, r = n - 1; l < r;) {
    int soma = v[l].first + v[r].first;
    if (soma == x) {
      if (v[l].second < v[r].second)
        cout << v[l].second + 1 << " " << v[r].second + 1 << "\n";
      else
        cout << v[r].second + 1 << " " << v[l].second + 1 << "\n";
      return 0;
    } else if (soma > x)
      r--;
    else
      l++;
  }

  cout << "IMPOSSIBLE" << "\n";
}
