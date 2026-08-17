#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int dist;
  int a, b;
};
#define MAXN 50500  // máximo de nodes
#define MAXM 200200 // máximo de arestas

bool comp(Edge a, Edge b) { return a.dist < b.dist; }

int pai[MAXN], sz[MAXN];
Edge edges[MAXM], mst[MAXM];
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

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= m; i++) {
    cin >> edges[i].a >> edges[i].b >> edges[i].dist;
  }
  init(n);
  sort(edges + 1, edges + m + 1, comp);

  int mstSz = 0; // quantidade de arestas
  for (int i = 1; i <= m; i++) {
    if (find(edges[i].a) !=
        find(edges[i].b)) { // se a aresta não forma ciclo, ou seja, se
                            // estiverem em componentes conex distintas
      join(edges[i].a, edges[i].b);

      mst[++mstSz] = edges[i]; // incremento dessa forma pois, se eu começar a
                               // var com 1 e ir pós incrementando, no fim, ia
                               // contar uma quantidade a mais no tamanho
    }
  }
  cout << "\n";
  for (int i = 1; i <= mstSz; i++) { // imprimir mst
    cout << mst[i].a << " " << mst[i].b << " " << mst[i].dist << endl;
  }

  return 0;
}
