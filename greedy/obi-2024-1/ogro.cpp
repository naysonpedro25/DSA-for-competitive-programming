#include "bits/stdc++.h"
using namespace std;

//https://neps.academy/br/exercise/2710
int main() {
  int e, d;
  cin >> e >> d;
  if (e > d)
    cout << e + d;
  else
    cout << 2 * (d - e);

  return 0;
}