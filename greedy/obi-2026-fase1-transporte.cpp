// https://neps.academy/br/exercise/3889
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;
  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  int i = 0, res = 0;
  while (i < n) {
    int l = v[i] + t;
    while (i < n && v[i] <= l)
      i++;
    res++;
  }
  cout << res;
  return 0;
}
