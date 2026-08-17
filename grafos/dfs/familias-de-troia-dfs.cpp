#include "bits/stdc++.h"
#include <vector>

using namespace std;
//  Farei de um jeito para aprender, ou seja, contar quantidade de cada item de
//  uma componente conexa
// https://neps.academy/br/course/algoritmos-em-grafos/lesson/familias-de-troia

#define MAXN 100000
int componenteNum[MAXN];
vector<int> adj[MAXN];
int dfs(int node) {

  int count = 1;
  for (int i = 0; i < adj[node].size(); i++) {
    int visinho = adj[node][i];
    if (componenteNum[visinho] == -1) {

      componenteNum[visinho] = componenteNum[node];
      count += dfs(visinho);
    }
  }
  return count;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    componenteNum[i] = -1;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int numComponent = 0;

  for (int i = 0; i < n; i++) {
    if (componenteNum[i] == -1) {
      componenteNum[i] = numComponent; // prcuro os itens da componente numero 0
      cout << dfs(i) << " ";           // imprimo o tamanho
      numComponent++; // coloco para procurar a de componente numero 1, ao mesmo
                      // tempo já conto 1 na contagem de componentes conexas
    }
  }

  cout << "\n" << numComponent;
  // for(int i = 0; i < n;i++) visited[
  return 0;
}