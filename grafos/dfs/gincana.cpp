#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
// https://neps.academy/br/course/algoritmos-em-grafos/lesson/familias-de-troia
vector<vector<int>> adj;
bool mark[50000];
void dfs(int n) {

  mark[n] = 1;
  stack<int> s;
  s.push(n);

  while (!s.empty()) {
    int node = s.top();
    s.pop();
    for (int node : adj[n]) {
      if (!mark[node]) {
        mark[node] = 1;
        s.push(node);
      }
    }
  }
}

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
    if (!mark[i]) {
      dfs(i);
      count++;
    }
  }
  cout << count;

  return 0;
}
