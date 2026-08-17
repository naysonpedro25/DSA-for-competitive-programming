#include "bits/stdc++.h"
#include <algorithm>
#include <iostream>
#include <vector>
// https://neps.academy/br/exercise/3129

#define LL long long
using namespace std;
int main() {

  int n;
  cin >> n;

  vector<LL> ps(n);
  for (LL &i : ps)
    cin >> i;
  sort(ps.begin(), ps.end());

  int count = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int l = 0, r = i - 1; l < r;) {
      int soma = ps[l] + ps[r];
      if (soma > ps[i]) {
        count += r - l;
        r--;
      } else
        l++;
    }
  }
  cout << count;

  return 0;
}