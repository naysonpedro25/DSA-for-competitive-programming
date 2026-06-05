#include "bits/stdc++.h"
#include <vector>

using namespace std;

#define LL long long

// https://neps.academy/br/exercise/255

int main() {
  int n, k;
  cin >> n;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;
  cin >> k;
  int r = n - 1, l = 0;
  while (l < n) {
    int soma = v[r] + v[l];
    if (soma > k) {
      r--;
    } else if (soma < k) {
      l++;
    } else {
      cout << v[l] << " " << v[r];
      break;
    }
  }
  return 0;
}
// 1 2 3 5