#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> r = {0,0,0,0};
  int n = r.size();
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    v[i].first = i - r[i];
    v[i].second = i + r[i];
  }
  n--;
  int alc = 0, maxAlc = 0, i = 0, cnt = 0;

  sort(v.begin(), v.end());

  while (alc < n) {
    while (i <= n && alc >= v[i].first) {
      maxAlc = max(maxAlc, v[i].second);
      i++;
    }

    if (maxAlc == alc){
        cout << 0;
        return 0;
    }
    alc = maxAlc;
    cnt++;
  }
  cout << cnt;

  return 0;
}
