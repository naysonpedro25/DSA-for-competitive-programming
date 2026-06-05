#include "bits/stdc++.h"

using namespace std;

int main() {

  vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n = v.size();

  int pref = 0, menorPref = 0, somaMax = INT_MIN;

  for (int i = 0; i < n; i++) {
    pref += v[i];

    int somaSub = pref - menorPref;

    somaMax = max(somaMax, somaSub);

    menorPref = min(menorPref, pref);
  }

  cout << somaMax;
  return 0;
}

/*

Um erro muito burro mais importante a se atentar:
Um raciocínio que me veio a mente foi achar o menor prefixo global. Esse erro de
lógica ignora uma restrição básica da soma de prefixo.

A resoluçaõ desse probelam se baseia na premissa:

soma(i,j) = pref[j] - pref[i -1], para maximar a soma, minizamos pref[i - 1] e
testamos os pref[j] possíveis. Mas para isso, devemos nos atentar no fato 
que i- 1 <= j, ou seja, a lógica anterior peca em tentar prever o futuro, e calcular
uma intervalo inexistente como real.



*/