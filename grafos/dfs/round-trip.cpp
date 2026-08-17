
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
// https://cses.fi/problemset/task/1669
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> v;
int mStart = -1, mEnd;

bool dfs(int node, int p) {
  v[node] = 1;
  parent[node] = p;

  for (int i : adj[node]) {

    if (!v[i]) {
      if (dfs(i, node))
        return true;
    } else if (i != p) {
      mEnd = node;
      mStart = i;
      return true;
    }
  }

  return false;
}

// p1 = 1, p2 = 1, p3 = 2, p3[1, 2] 1 != 3

int main() {

  int n, m;
  cin >> n >> m;

  adj.resize(n + 1);
  parent.resize(n + 1);
  v.resize(n + 1);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i <= n; i++) {
    if (!v[i]) {
      parent[i] = -1;
      if (dfs(i, i)) {
        // mStart = i; Não pode ser aqui, a raiz do ciclo pode ser encontrada
        // muito longe
        break;
      }
    }
  }

  if (mStart == -1) {
    cout << "IMPOSSIBLE";
  } else {

    deque<int> path;

    for (int v = mEnd; v != mStart; v = parent[v])
      path.push_front(v);

    path.push_front(mStart);
    path.push_back(mStart);

    cout << path.size() << endl;

    for (int i : path) {
      cout << i << " ";
    }
  }

  return 0;
}
/*
Questão que vale a pena revisar
*/