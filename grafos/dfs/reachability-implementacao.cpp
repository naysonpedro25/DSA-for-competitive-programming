#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> adj;
bool vis[10000];


void dfs(int s){
    vis[s] = 1;

    for(int v : adj[s]){
        
    }
}

int main() {
  int n, m, s;

  cin >> n >> m >> s;
  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    adj[a].push_back(b);
  }

  return 0;
}
