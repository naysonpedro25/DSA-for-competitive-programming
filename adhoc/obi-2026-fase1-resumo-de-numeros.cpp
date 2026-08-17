// https://neps.academy/br/exercise/3890
#include <bits/stdc++.h>
using namespace std;

int main() {
  string n;
  cin >> n;

  int res = 0;

  while (1) {
    string m = "";
    int t = n.size();

    int i = 0, p = 0;
    for (char c : n) {
      if ((c - '0') % 2 == 0)
        p++;
      else
        i++;
    }
    m.push_back(t + '0');
    m.push_back(i + '0');
    m.push_back(p + '0');

    if (m == n) {
      break;
    }
    n = m;
    res++;
  }

  cout << res;

  return 0;
}
