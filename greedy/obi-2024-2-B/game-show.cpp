#include "bits/stdc++.h"
// https://neps.academy/br/exercise/3127
using namespace std;
int main() {

  int n;
  string d;
  cin >> n >> d;
  int cur = 1;
  for (char c : d) {
    if (c == 'E')
      cur *= 2;
    else
      cur = 2 * cur + 1;
  }
  cout << cur;

  return 0;
}