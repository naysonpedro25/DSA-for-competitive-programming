#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://cses.fi/problemset/task/1084
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n), a(m);

  for (int &i : v)
    cin >> i;
  for (int &i : a)
    cin >> i;

  sort(v.begin(), v.end());
  sort(a.begin(), a.end());
  int res = 0;
  int i = 0, j = 0;

  while (i < n && j < m) {
    if (a[j] >= v[i] - k && a[j] <= v[i] + k) {
      res++;
      j++;
      i++;
    } else if (a[j] < v[i] - k)
      j++;
    else
      i++;
  }

  cout << res;
  return 0;
}
