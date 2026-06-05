#include "bits/stdc++.h"

using namespace std;

int main() {

  int n, x;
  cin >> n >> x;
  vector<int> v(n * 2);
  int total = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    total += v[i];
  }
  int soma = 0;
  int res = 0;
  for (int l = 0, r = 0; r < n; r++) {
    soma += v[r];

    while (soma > x && l <= r) {
      soma -= v[l];
      l++;
    }
    if (soma == x) {
      res++;
    }
  }

  x = total - x;

  if (x >= 0) {
    soma = 0;
    for (int l = 0, r = 0; r < n; r++) {
      soma += v[r];

      while (soma > x && l <= r) {
        soma -= v[l];
        l++;
      }
      if (soma == x && (l != 0 && r != n - 1)) {
        res++;
      }
    }
  }

  cout << res;
}

// 1 2 3 4 3 0 1 3 6 10 13

//     13 -
//     10 = 3;
