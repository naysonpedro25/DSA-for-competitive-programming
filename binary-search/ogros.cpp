#include "bits/stdc++.h"
#include <algorithm>
#include <iterator>

using namespace std;
// https://neps.academy/br/submission/1677798
int main() {

  int n, m;

  cin >> n >> m;

  vector<int> faixas(n - 1);
  vector<int> premios(n);

  for (int i = 0; i < n - 1; i++)
    cin >> faixas[i];
  for (int i = 0; i < n; i++)
    cin >> premios[i];
  for (int i = 0; i < m; i++) {
    int o;
    cin >> o;

    // for(int j = 0;j  < faixas.size(); j++){
    auto it = lower_bound(faixas.begin(), faixas.end(), o);
    int val = *it;
    int index = distance(faixas.begin(), it);

    if (it == faixas.end()) {
      cout << premios[n - 1] << " ";
    } else if (o >= val)
      cout << premios[index + 1] << " ";
    else
      cout << premios[index] << " ";
  }

  return 0;
}