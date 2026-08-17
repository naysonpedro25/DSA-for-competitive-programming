#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://cses.fi/problemset/task/1074
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<int> v(n);

  for (int &i : v)
    cin >> i;

  long long maxLocal = 0;
  long long maxGlobal = INT_MIN;
  for (int i = 0; i < n; i++) {
    maxLocal = max((long long)v[i], v[i] + maxLocal);
    maxGlobal = max(maxLocal, maxGlobal);
  }

  cout << maxGlobal;

  return 0;
}
