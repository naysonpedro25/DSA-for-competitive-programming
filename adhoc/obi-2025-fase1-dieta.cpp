#include "bits/stdc++.h"
#include <algorithm>
#include <vector>
// https://neps.academy/br/exercise/3121

using namespace std;

int main() {
  int m, n;
  cin >> n >> m;
  int soma = 0;
  while (n--) {
    int p, g, c;
    cin >> p >> g >> c;
    soma += p * 4 + g * 9 + c * 4;
  }
  cout << m - soma;
}