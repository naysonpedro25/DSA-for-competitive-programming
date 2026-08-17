#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  vector<int> q;
  for (int i = 0; i < n; i++) {
    auto it = upper_bound(q.begin(), q.end(), v[i]);
    if (it != q.end()) {
      *it = v[i];
    } else {
      q.push_back(v[i]);
    }
  }

  cout << q.size();

  return 0;
}
