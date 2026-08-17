#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int>> adj;

bool res = true;

// https://neps.academy/br/exercise/354
int dfs(int node) {
  if (!res)
    return 0;

  int sum = 1;

  int base = -1;

  for (int i = 0; i < adj[node].size(); i++) {
    int nxt = adj[node][i];

    int count = dfs(nxt);

    if (base == -1)
      base = count;
    else if (base != count) {
      res = false;
    }

    sum += count;
  }

  return sum;
}

int main() {
  int n;
  cin >> n;
  adj.resize(n + 1);

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    adj[b].push_back(a);
  }

  dfs(0);

  if (res)
    cout << "bem\n";
  else
    cout << "mal\n";

  return 0;
}
