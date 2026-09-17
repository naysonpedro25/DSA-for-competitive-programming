#include <algorithm>
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
typedef pair<int, int> pii;

const int MAXN = 1e5 + 10;
int pai[MAXN], sz[MAXN];

pii edge[MAXN];

int find(int x) {
  if (pai[x] == x)
    return x;

  return pai[x] = find(pai[x]);
}

void join(int x, int y) {
  x = find(x);
  y = find(y);

  if (x == y)
    return;

  if (sz[x] >= sz[y]) {
    pai[y] = x;
    sz[x] += sz[y];
  } else {
    pai[x] = y;
    sz[y] += sz[x];
  }
}

void init(int n) {
  for (int i = 1; i <= n; i++) {
    pai[i] = i;
    sz[i] = 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  init(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edge[i] = {a, b};
  }
  vector<pair<string, pii>> queires;
  set<pii> mk;

  for (int i = 0; i < k; i++) {
    string q;
    int a, b;
    cin >> q >> a >> b;
    queires.push_back({q, {a, b}});
    if (q == "cut") {
      mk.insert({a, b});
      mk.insert({b,a});
    }
  }

  for (int i = 0; i < m; i++) {
    auto [a, b] = edge[i];
    if (!mk.count({a,b}) && !mk.count({b,a})) {
      join(a, b);
    }
  }

  vector<string> res;

  for (int i = k - 1; i >= 0; i--) {
    string q = queires[i].first;
    auto [a, b] = queires[i].second;
    if (q == "ask") {
      if (find(a) == find(b)) {
        res.push_back("YES");
      } else {
        res.push_back("NO");
      }
    } else {
      join(a, b);
    }
  }

  reverse(res.begin(), res.end());
  for (string s : res) {
    cout << s << endl;
  }

  return 0;
}
