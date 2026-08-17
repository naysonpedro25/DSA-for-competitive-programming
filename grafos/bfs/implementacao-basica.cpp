#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int MAXN = 100000;

bool visited[MAXN];
vector<vector<int>> adj;

void bfs(int init) {

  queue<int> q;
  q.push(init);
  visited[init] = 1; // se eu quisesse , no for que perorre os nodes, marcaria
                     // logo ali o primeiro visto de uma componente conexa caso não fosse

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (int v : adj[node]) {
      if (!visited[v]) {
        visited[v] = 1;
        q.push(v);
      }
    }
  }
}

int main() {
  int n;
  adj.resize(n);

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bfs(i);
      count++;
    }
  }

  return 0;
}
