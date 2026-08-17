#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://neps.academy/br/exercise/3267
int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> mt(n, vector<int>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mt[i][j];
    }
  }

  int cntP = 0, cntI = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        if (mt[i][j] % 2 != 0)
          cntP++;
      } else {
        if (mt[i][j] % 2 == 0)
          cntP++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0) {
        if (mt[i][j] % 2 == 0)
          cntI++;
      } else {
        if (mt[i][j] % 2 != 0)
          cntI++;
      }
    }
  }

  if (cntI > cntP) {
    cout << cntP << "\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 0) {
          if (mt[i][j] % 2 != 0)
            mt[i][j]++;
        } else {
          if (mt[i][j] % 2 == 0)
            mt[i][j]++;
        }

        cout << mt[i][j] << " ";
      }
      cout << '\n';
    }
  } else {
    cout << cntI << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if ((i + j) % 2 == 0) {
          if (mt[i][j] % 2 == 0)
            mt[i][j]++;
        } else {
          if (mt[i][j] % 2 != 0)
            mt[i][j]++;
        }

        cout << mt[i][j] << " ";
      }
      cout << '\n';
    }
  }

  return 0;
}
/*
Perdi meu tempo revisando grafos bipartidos, mas era bem mais simples. Comecei
com um greedy, depois grados pra no fim descobri o padrão besta: depois de
decidir o primeiro, toda a paridade da matriz é decidida junta. Assim, se
escolho 0,0 como par dá pra saber que todo i + j % 2 == 0 precisa ser par também
e virse versa. Assim no fim era só comparar qual era o menor começar por par ou
por impar

*/