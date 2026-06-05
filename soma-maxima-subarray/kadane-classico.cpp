#include "bits/stdc++.h"
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  // se os valores forem apenas negativos, da ruim
  vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n = v.size();

  int somaMax = INT_MIN;
  int somaLocal = v[0];
  for (int i = 1; i < n; i++) {
    if (somaLocal < 0) // soma anterior for menor que 
      somaLocal = 0;

    somaLocal += v[i];
    somaMax = max(somaLocal, somaMax);
  }

  cout << somaMax;

  return 0;
}