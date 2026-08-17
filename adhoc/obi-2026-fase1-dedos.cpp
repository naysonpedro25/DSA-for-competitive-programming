// https://neps.academy/br/exercise/3886
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {

  int d[5];
  for (int &i : d)
    cin >> i;

  int v = 16;
  int res = 0;
  for (int i : d) {
    if (i) {
      res += v;
    }
    v /= 2;
  }
  cout << res;
  return 0;
}
