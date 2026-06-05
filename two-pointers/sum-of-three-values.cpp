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

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int l = i + 1, r = n - 1; l < r;) {
      sum = v[i].first + v[l].first + v[r].first;
      if (sum > x)
        r--;
      else if (sum < x)
        l++;
      else {
        int res[3] = {v[i].second, v[l].second, v[r].second};
        sort(res, res + 3);
        for (int rs : res)
          cout << rs + 1 << " ";
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
  return 0;
}
