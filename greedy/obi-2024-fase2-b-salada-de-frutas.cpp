#include "bits/stdc++.h"
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
#include <vector>

// https://neps.academy/br/exercise/3128
using namespace std;

int m[10000];

int main() {

  int r, n;
  cin >> r >> n;
  vector<pair<int, int>> tb(n);

  for (int i = 0; i < n; i++) {
    cin >> tb[i].first;
    cin >> tb[i].second;
  }

  sort(tb.begin(), tb.end(), [](pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
  });
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (!m[tb[i].first]) {
      if (r - tb[i].second >= 0) {
        r -= tb[i].second;
        res += 1;
        m[tb[i].first] = 1;
      } else
        break;
    }
  }
  cout << res;
  return 0;
}