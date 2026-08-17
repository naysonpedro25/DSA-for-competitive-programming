#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
//https://neps.academy/br/exercise/265
int main() {
  int n, l;
  cin >> n >> l;
  vector<int> v(l), res(n, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int i = 0; i < l; i++)
    cin >> v[i];

  if (l <= n) {
    for (int i = 0; i < l; i++) {
      pq.push({v[i], i});
      res[i] += 1;
    }

    for (int i = 0; i < n; i++) {
      cout << i + 1 << " " << res[i] << '\n';
    }

    return 0;
  }

  for (int i = 0; i < n; i++) {
    pq.push({v[i], i});
    res[i] += 1;
  }

  for (int i = n; i < l; i++) {
    auto f = pq.top();
    pq.pop();

    res[f.second]++;
    f.first += v[i];
    pq.push(f);
  }

  for (int i = 0; i < n; i++) {
    cout << i + 1 << " " << res[i] << '\n';
  }

  return 0;
}

// eu nunca fiquei tanto tempo numa questão por conta de um simples sinal
/*
Eu tentei de tudo, uma fila secundária, um while para filtrar os atendentes
livres, mas nenhum funcionou Isso tudo porque eu não sabia que simplesmente
somar o valor do tempo em cada funcionário era a melhor opção.
Mais ou menos 2 h e meia nese problema para isso.

*/