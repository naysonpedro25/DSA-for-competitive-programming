#include "bits/stdc++.h"
#include <algorithm>
#include <vector>
//https://neps.academy/br/exercise/2710

using namespace std;
int main() {
  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  for (int i = n - 1; i >= 0; i--) {
    --k;
    if (k == 0) {
      cout << v[i];
      break;
    }
  }

  return 0;
}