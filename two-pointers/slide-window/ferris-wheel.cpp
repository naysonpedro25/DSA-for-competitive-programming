#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1090
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;
  sort(v.begin(), v.end());
  int res = 0;
  int j = n - 1;
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    while (i < j && v[i] + v[j] > x) {
      j--;
    }
    if (i < j && v[i] + v[j] <= x) {
      cnt++;
      j--;
    }
  }

  cout << n - cnt;

  return 0;
}
