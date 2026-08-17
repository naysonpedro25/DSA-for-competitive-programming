#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
vector<vector<int>> adj;
bool vis[MAXN];
int dist[MAXN];

int bfs(int st) {

  vis[st] = 1;
  dist[st] = 0;

  queue<int> q;
  q.push(st);

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int v : adj[node]) {
      if (vis[v])
        continue;

      vis[v] = 1;
      dist[v] = dist[node] + 1;
      q.push(v);
    }
  }
  return -1;
}

int main() {
  int n, m, s;
  cin >> n >> m >> s;

  adj.resize(n);
  for (int i = 0; i < n; i++)
    dist[i] = -1;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[--a].push_back(--b);
  }
  bfs(--s);

  for (int i = 0; i < n; i++)
    cout << dist[i] << " ";

  return 0;
}
