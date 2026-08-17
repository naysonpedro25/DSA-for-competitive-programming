#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>
// https://neps.academy/br/exercise/3266
using namespace std;

struct item {
  int id;
  int tipo;
  int preco;
  bool vendido;
};

vector<item> v;

struct comp {
  bool operator()(int id1, int id2) const {
    return tie(v[id1].preco, v[id1].tipo) > tie(v[id2].preco, v[id2].tipo);
  }
};

int main() {
  int t, n;
  cin >> n >> t;

  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].tipo;
    v[i].vendido = false;
    v[i].id = i;
  }
  for (int i = 0; i < n; i++)
    cin >> v[i].preco;

  unordered_map<int, priority_queue<int, vector<int>, comp>> tp;
  priority_queue<int, vector<int>, comp> pg;

  for (int i = 0; i < n; i++) {
    tp[v[i].tipo].push(v[i].id);
    pg.push(v[i].id);
  }

  int c;
  cin >> c;
  long long res = 0;

  while (c--) {

    int ci;
    cin >> ci;

    if (ci != 0) {
      if (!tp.count(ci))
        continue;

      while (!tp[ci].empty() && v[tp[ci].top()].vendido) {
        tp[ci].pop();
      }
      if (!tp[ci].empty()) {
        int id = tp[ci].top();
        res += v[id].preco;
        v[id].vendido = true;
        tp[ci].pop();
      }

    } else {

      while (!pg.empty() && v[pg.top()].vendido) {
        pg.pop();
      }
      if (!pg.empty()) {
        int id = pg.top();
        res += v[id].preco;
        v[id].vendido = true;
        pg.pop();
      }
    }
  }

  cout << res;

  return 0;
}
// gpt deu a call do id e do comp diferente.
// outra coisa importante, sempre verificar o tamanho do inteiro, o res tipo int
// ia estourar fácil, só foi mudar isso que o WA sumiu