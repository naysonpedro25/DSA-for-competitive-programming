
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
// https://cses.fi/problemset/task/1667
using namespace std;

vector<vector<int>> adj;
vector<int> parent, dist;

bool bfs(int node) {
  dist[node] = 0;
  parent[node] = -1;
  queue<int> q;
  q.push(node);

  while (!q.empty()) {
    int n = q.front();
    q.pop();

    for (int vi : adj[n]) {
      if (dist[vi] == -1) {
        dist[vi] = dist[n] + 1;
        parent[vi] = n;
        q.push(vi);
      }
    }
  }

  return true;
}

int main() {

  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  parent.resize(n + 1);
  dist.resize(n + 1);
  fill(dist.begin(), dist.end(), -1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfs(1);

  if (dist[n] == -1) {
    cout << "IMPOSSIBLE";
  } else {
    deque<int> path;

    int v = n;
    while (v != -1) {
      path.push_front(v);
      v = parent[v];
    }

    cout << path.size() << endl;

    for (int i : path) {
      cout << i << " ";
    }
  }

  return 0;
}
