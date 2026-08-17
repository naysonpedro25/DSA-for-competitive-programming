#include "bits/stdc++.h"
#include <unordered_set>
#include <vector>

using namespace std;
// https://neps.academy/br/exercise/2323
// matriz de adjacência

// #define ll long long
int main() {

  int s, t;
  cin >> s >> t;

  vector<unordered_set<int>> g(s);

  for (int i = 0; i < t; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;

    g[x].insert(y);
    g[y].insert(x);
  }

  int p;
  cin >> p;
  int res = 0;

  while (p--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int &i : c) {
      cin >> i;
      i--;
    }

    bool isValid = true;

    for (int i = 0; i < n - 1; i++) {
      int v1 = c[i];
      int v2 = c[i + 1];

      if (g[v1].count(v2) == 0) {
        isValid = false;
        break;
      }
    }

    if (isValid)
      res++;
  }
  cout << res;

  return 0;
}
