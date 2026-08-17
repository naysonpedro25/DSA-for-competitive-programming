// https://neps.academy/br/exercise/3888
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int res = 0;

  while (n > 0) {
    if (n >= 10)
      n -= 10;
    else if (n >= 5)
      n -= 5;
    else if (n >= 2)
      n -= 2;
    else
      n -= 1;
    res++;
  }

  cout << res;
  return 0;
}
