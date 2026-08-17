// https://cses.fi/problemset/task/1085
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#define INT long long

using namespace std;
int main() {

  int n, k;
  cin >> n >> k;

  vector<int> v(n);

  for (INT i = 0LL; i < n; i++)
    cin >> v[i];

  INT ini = *max_element(v.begin(), v.end()), fim = accumulate(v.begin(), v.end(), 0LL), mid;

  INT sol = fim;
  while (ini <= fim) {
    mid = (fim + ini) / 2;

    INT sum = 0;
    INT count = 1;

    for (int i = 0; i < n; i++) {
      if (sum + v[i] > mid) {
        count++;
        sum = v[i];
      } else
        sum += v[i];
    }

    if (count <= k) {
      sol = min(sol, mid);
      fim = mid - 1;
    } else
      ini = mid + 1;
  }

  cout << sol;
  return 0;
}

/*

Erros

1- LIMITES MAL DEFINIDOS, eu defini o limte ini errado e contava um errado por algum motivo

*/