
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  int t;
  cin >> t;

  while (t--) {
    int n, c;
    cin >> n >> c;

    vector<int> loc(n);
    for (int i = 0; i < n; i++)
      cin >> loc[i];

    sort(loc.begin(), loc.end());

    int ini = 0, fim = *max_element(loc.begin(), loc.end()), mid;

    int sol = 0;

    while (ini <= fim) {
      mid = (fim + ini) / 2;
      int count = 1;
      int las = loc[0];
      for (int i = 1; i < n; i++) {
        if (loc[i] >= las + mid) {
          count++;
          las = loc[i];
        }
      }

      if (count >= c) {
        sol = max(sol, mid);
        ini = mid + 1;
      } else {
        fim = mid - 1;
      }
    }
    cout << sol << "\n";
  }
  return 0;
}

/* 
Erros

1 - não soube identificar a condição para selecionar uma solução, ou seja, não sabia como verificar um mid era válido. No fim a ia me ajudou aqui, dizendo que essa verificação
era um greedy simples.
2 - limites da busca binária, usei o fim = maior elemento, mas esse limite n é o ideal, sendo que os limites seriam a menor e a maior distância entre 2 baias
3 - cometi a gafe de, na condição, comparava count com 3, sim literalmente 3
4 - Não soube no começo o que fazer com id, sendo que na maioria dos problemas com busca, o mid é exatamente o valor que eu to procurando maximizado ou minimizado para uma solução

*/