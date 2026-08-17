// https://neps.academy/br/exercise/3262
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  if (m - n >= 4 * (n - 1))
    cout << "S";
  else
    cout << "N";
  return 0;
}
