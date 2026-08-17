// https://neps.academy/br/exercise/3880
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int &i : p)
    cin >> i;

  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    res += abs(p[i] - p[1 + i]);
  }

  cout << res;
  return 0;
}
