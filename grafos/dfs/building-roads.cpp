#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
// https://cses.fi/problemset/task/1666
vector<vector<int>> adj;
bool v[1000010];

int dfs(int node) {
  v[node] = 1;
  int lest = -1;

  for (int i : adj[node]) {
    if (!v[i]) {
      dfs(i);
    }
  }

  return lest;
}

int main() {
  int n, m;
  cin >> n >> m;

  adj.resize(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int count = 0;

  vector<int> r;
  int f;
  for (int i = 0; i < n; i++) {
    if (!v[i]) {
      r.push_back(i + 1);
      dfs(i);
      count++;
    }
  }
  cout << count - 1 << '\n';
  if (r.size() == 1)
    return 0;
  for (int i = 0; i < r.size() - 1; i++) {
    cout << r[i] << " " << r[i + 1] << '\n';
  }

  return 0;
}
