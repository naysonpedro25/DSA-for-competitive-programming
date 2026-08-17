#include <bits/stdc++.h>
#include <utility>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<pair<int, int>> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }

  sort(v.begin(), v.end());
  int res = 1;

  for (int i = 0; i < n - 1; i++) {
    if (v[i].second > v[i + 1].second)
      res++;
  }

  cout << res;

  return 0;
}
