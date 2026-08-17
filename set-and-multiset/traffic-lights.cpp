#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int x, n;
  cin >> x >> n;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  set<int> st;
  multiset<int> ms;

  for (int i = 0; i < n; i++) {
    auto itMaior = st.end();
    auto itMenor = st.end();
    if (!st.empty()) {
      itMaior = st.upper_bound(v[i]);
      itMenor = st.lower_bound(v[i]);
    }

    int lmaior = x, lmenor = 0;
    if (itMenor != st.begin()) {
      --itMenor;
      lmenor = *itMenor;
    }

    if (itMaior != st.end()) {
      lmaior = *itMaior;
    }
    auto it = ms.find(lmaior - lmenor);
    if (!ms.empty() && it != ms.end()) {
      ms.erase(it);
    }
    st.insert(v[i]);
    ms.insert(abs(v[i] - lmenor));
    ms.insert(abs(lmaior - v[i]));

    cout << (*ms.rbegin()) << ' ';
  }

  return 0;
}
// lower_bound(v[i]) retorna:
// 1. um elemento no meio  -> prev() pega o elemento à esquerda;
// 2. begin()              -> NÃO existe elemento à esquerda, então não podemos voltar;
// 3. end()                 -> significa que v[i] é maior que todos,
//                              e prev(end()) pega corretamente o maior elemento.
//
// Por isso basta testar:
//     if (itMenor != st.begin()) --itMenor;
//
// Esse teste cobre todos os casos: se for begin(), não decrementa;
// se for qualquer outro iterador (inclusive end()), decrementa com segurança.
