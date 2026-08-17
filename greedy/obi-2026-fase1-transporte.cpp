// https://neps.academy/br/exercise/3889
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int res = 0;

  int l = 0, r = 0;

  for (; r < n; r++) {
    if (v[r] - v[l] > t) {
      res++;
      l = r;
    }
  }

  // while (l <= r && r < n) {
  //   if (v[r] - v[l] <= t)
  //     r++;
  //   else {
  //     l = r;
  //     res++;
  //   }
  // }

  if (v[r - 1] - v[l] > t) // dois ultimos forem por exemplo 42 e 60 com t = 10
                           // precisariamos de 2 ônibus
    res += 2;
  else
    res++;

  cout << res;

  return 0;
}
