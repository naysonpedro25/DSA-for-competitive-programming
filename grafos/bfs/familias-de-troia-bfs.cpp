#include "bits/stdc++.h"

using namespace std;
// https://neps.academy/br/course/algoritmos-em-grafos/lesson/familias-de-troia
vector<vector<int>> adj;
bool visited[1000000];

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

  for (int i = 0; i < n; i++) {

    if (!visited[i]) {

      count++;
      visited[i] = 1;

      queue<int> q;
      q.push(i);

      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int next : adj[node]) {
          if (visited[next])
            continue;
          visited[next] = 1;
          q.push(next);
        }
      }
    }
  }

  cout << count;
  return 0;
}