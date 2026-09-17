#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (auto &i : v)
    cin >> i.first >> i.second;

  sort(v.begin(), v.end(), [](auto a, auto b){
    return a.second < b.second;
  });

  int res = 0, ent = -1;
  for (int i = 0; i < n; i++) {
    if (v[i].first >= ent){
      res++;
      ent = v[i].second;
    }
  }

  cout << res;

  return 0;
}
