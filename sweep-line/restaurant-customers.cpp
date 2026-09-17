// https://cses.fi/problemset/task/1619
#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <vector>
using namespace std;

struct Ev {
  int tipo, val;
  Ev(int t, int v) {
    tipo = t;
    val = v;
  }

  bool operator<(Ev &other) {
    if (val == other.val)
      return tipo < other.tipo;
    return val < other.val;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<Ev> v;

  for (int i = 0; i < n; i++) {
    int e, s;
    cin >> e >> s;

    v.push_back(Ev(1, e));
    v.push_back(Ev(2, s));
  }

  sort(v.begin(), v.end());

  int res = 0, count = 0;
  for (Ev e : v) {
    if (e.tipo == 1) {
      count++;
    } else {
      count--;
    }

    res = max(res, count);
  }

  cout << res;

  return 0;
}