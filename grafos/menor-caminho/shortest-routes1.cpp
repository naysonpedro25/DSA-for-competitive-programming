#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

typedef pair<long long, long long> pll;
const int MAXN = 1e5 + 10;
long long dist[MAXN];
bool mark[MAXN];

vector<vector<pll>> adj; // (node, peso)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  adj.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    long long w;

    cin >> a >> b >> w;
    adj[a].push_back({b, w});
  }
  for (int i = 1; i <= n; i++) {
    dist[i] = LLONG_MAX;
  }
  int S = 1; // ponto de partide, o alg acha a menor distancia de todos os
             // vértices em relação a S

  dist[S] = 0;

  priority_queue<pll, vector<pll>, greater<pll>>
      q; // guarda a distância atual de cada vértice em ordem crescente (peso,
         // node)

  q.push({dist[S], S}); // incialmente apenas a origem

  while (!q.empty()) {
    int cur = q.top().second; // pego o vértice
    q.pop();

    if (mark[cur])
      continue;

    mark[cur] = 1;

    for (pll v : adj[cur]) {
      auto [visinho, peso] = v;
      if (dist[visinho] > dist[cur] + peso) { // -< não entendi essa parte
        dist[visinho] = dist[cur] + peso;
        q.push({dist[visinho], visinho});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << ' ';
  }

  // além disso, como eu sei qual é o menor caminho? tipo como eu printo os nós
  // que tem o menor cainho?

  return 0;
}
/* Uma distinção bem importante: A fila de prioridade guarda {peso, vértice}, já
 * a lista de adj guarda {vértice, peso} */