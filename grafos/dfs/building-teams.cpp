
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> color;

// https://cses.fi/problemset/task/1668

bool bfs(int node) {
  color[node] = 1;
  queue<int> q;
  q.push(node);

  while (!q.empty()) {
    int n = q.front();
    q.pop();

    for (int v : adj[n]) {
      if (color[v] == -1) {
        color[v] = 3 - color[n]; // 1 ou 2
        q.push(v);
      } else if (color[v] == color[n])
        return false;
    }
  }

  return true;
}

bool dfs(int node) {
  // uma forma mais de boa, sem precisar definir a primeira cor
  // era definir a cor antes do for como color[node] = c; e receber a cor no
  // parametro como c - color[node]
  for (int i : adj[node]) {
    if (color[i] == -1) {
      color[i] = 3 - color[node];
      if (!dfs(i))
        return false;
    } else if (color[i] == color[node]) {
      return false;
    }
  }

  return true;
}

int main() {

  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  color.resize(n + 1);
  fill(color.begin(), color.end(), -1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (color[i] == -1) {
      // color[i] = 1; isso com a dfs
      if (!bfs(i)) {
        cout << "IMPOSSIBLE";
        return 0;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << color[i] << " ";
  }

  return 0;
}
