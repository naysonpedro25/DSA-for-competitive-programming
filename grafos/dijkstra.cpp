#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, long long>>> graph(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    long long w;

    cin >> a >> b >> w;

    graph[a].push_back({b, w});
  }

  vector<long long> dist(n + 1, LLONG_MAX);

  // { -distância, vértice }
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>
      dj;

  dist[1] = 0;
  dj.push({0, 1});

  while (!dj.empty()) {
    long long distatual = -dj.top().first;
    int vatual = dj.top().second;

    dj.pop();

    // Essa entrada ficou desatualizada
    if (distatual != dist[vatual])
      continue;

    for (auto neighbor : graph[vatual]) {
      int v = neighbor.first;
      long long peso = neighbor.second;

      if (dist[v] > distatual + peso) {
        dist[v] = distatual + peso;

        dj.push({-dist[v], v});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }

  return 0;
}