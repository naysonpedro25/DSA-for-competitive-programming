#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <unordered_set>
using namespace std;
// https://cses.fi/problemset/task/1091
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  multiset<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.insert(a);
  }


  while (m--) {
    int a;
    cin >> a;
    if (v.size() == 0) {
      cout << -1 << "\n";
      continue;
    }
    auto it = v.upper_bound(a);
    if (it == v.begin()) {
      cout << -1 << "\n";
      continue;
    }
    --it;

    if (it != v.end()) {
      cout << *it << "\n";
      v.erase(it);
    } else
      cout << -1 << "\n";
  }

  return 0;
}
