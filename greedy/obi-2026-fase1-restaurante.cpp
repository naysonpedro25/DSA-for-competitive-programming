// https://neps.academy/br/exercise/3882
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a1, a2, a3, a4;
  cin >> a1 >> a2 >> a3 >> a4;

  int res = 0;

  res += a4;

  while (a1 > 0 && a3 > 0) {
    res++;
    a1--;
    a3--;
  }

  if (a3 > 0) {
    res += a3;
  }

  res += a2 / 2;
  a2 %= 2;

  if (a2 > 0) {
    if (a1 > 0) {
      a1 -= 2;
    }
    res += 1;
    a2--;
  }

  if (a1 < 0)
    a1 = 0;

  res += a1 / 4;
  a1 %= 4;
  res += a1 > 0 ? 1 : 0;

  cout << res;

  return 0;
}
/*
Questão fácil, que testa a atenção do quem faz. O maior ponto é, casos testes de limites grandes e pequenos
o que eu mais demorei pra encontrar, que foi só com ia, foi o caso de 1 1 0 0, que dá 1 e não dois

*/
