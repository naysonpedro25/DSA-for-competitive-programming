#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://neps.academy/br/exercise/354
#define ll long long
vector<vector<ll>> adj;
vector<ll> visited;
bool res = true;

ll dfs(ll node) {
  visited[node] = 1;

  ll sum = 1;

  ll base = -1;

  for (ll i = 0; i < adj[node].size(); i++) {
    ll visinho = adj[node][i];
    if (visited[visinho])
      continue;

    ll count = dfs(visinho);

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
  ll n;
  cin >> n;
  adj.resize(n);
  visited.resize(n + 10);

  ll raiz = 0;
  for (ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;

    if (b == 0) {
      raiz = a - 1;
    } else {
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  dfs(raiz);

  if (res)
    cout << "bem";
  else
    cout << "mal";

  return 0;
}
