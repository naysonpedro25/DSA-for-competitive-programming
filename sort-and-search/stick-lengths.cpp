#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> v(n);

  for (int &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  int m = v[(n / 2)]; // (n /2) - 1 + 1

  long long res = 0;
  for (int i = 0; i < n; i++) {
    res += abs(v[i] - m);
  }

  cout << res;

  return 0;
}
