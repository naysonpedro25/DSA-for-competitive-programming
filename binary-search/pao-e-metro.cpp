// https://neps.academy/br/exercise/605
#include "bits/stdc++.h"
#include <algorithm>

#include <vector>

using namespace std;

int main() {

  int n, m;
  cin >> n >> m;
  vector<int> paes(m);
  for (int i = 0; i < m; i++)
    cin >> paes[i];

  int maxV = *max_element(paes.begin(), paes.end());

  int ini = 1, fim = maxV, mid;

  int sol = 0;

  while (ini <= fim) {
    mid = (fim + ini) / 2;
    int fati = 0;
    for (int i = 0; i < m; i++) {
      fati += paes[i] / mid;
    }

    if (fati >= n) // fatia muito grande
    {

      sol = max(sol, mid);
      ini = mid + 1;
    } else
      fim = mid - 1;
  }

  cout << sol;
  return 0;
}

/*

ERROS

1 - comecei com ini = 0, o que poderia claramente estourar em paes[i]/mid
2 - verificar se a quantidade de fatias calculada (fati) era exatamente igual a
n
  |_ Nesse caso, qualquer valor maior que n seria válido, a partir daí a busca
ainda ia continuar, aumentenando de 1 em 1 o tamanho da fatia até o limite, que
seria a maior fatia que o número de fatias ainda seria >=n 3 - Tentar dar break,
podando a busca com n==fati, isso é parar antes de achar a melhor resposta 4 -
no começo eu não guardei a melhor respsta, pensei que se eu acha-se o extato
valor eu já estaria com a melhor, bullshit

No fim, o conhecimento de lower_bound aqui era a chave, o ponto era interpretar
certo

*/