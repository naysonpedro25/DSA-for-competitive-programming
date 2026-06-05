#include "bits/stdc++.h"
using namespace std;
// https://neps.academy/br/exercise/2713
int main() {

  int h, m, s, t;
  cin >> h >> m >> s >> t;

  s += t;

  if (s >= 60) {
    m += s / 60;
    s %= 60;
  }

  if (m >= 60) {
    h += m / 60;
    m %= 60;
  }

  if (h >= 24) {
    h %= 24;
  }

  cout << h << endl;
  cout << m << endl;
  cout << s << endl;

  return 0;
}