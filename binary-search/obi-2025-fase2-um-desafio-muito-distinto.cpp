// https://neps.academy/br/exercise/3268
#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
int main() {
  int p;
  cin >> p;

  while (p--) {
    ll l, a, b;
    cin >> l >> a >> b;

    ll caixa = 0;
    int res = 1;

    ll ini = a, end = b, mid, maior = 0;

    while (ini <= end) {
      mid = (ini + end) / 2;

      __int128 soma = (__int128)(a + mid) * (mid - a + 1) / 2;

      if (soma < l) {
        ini = mid + 1;
        maior = mid;
      } else {
        end = mid - 1;
      }
    }

    if (maior != 0)
      res += maior - a + 1;

    if (maior == b) {
      res--;
    }

    // cout << maior << " " << soma << endl;
    cout << res << endl;

    // cout << maior << endl;
    // for (ll i = a; i <= b; i++) {
    //   caixa += i;
    //   res += 1;
    //   if (caixa >= l)
    //     break;
    // }
    // cout << res << '\n';
  }
  return 0;
}
/*

Questão de viado. Tem que ter de cabeça a merda do estouro do long long para
poder ir para o __int128 ou unsigned long long se não for um desses dois da TLE,
o pq tle eu não faço ideia
*/