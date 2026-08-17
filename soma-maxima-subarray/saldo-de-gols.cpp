#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
// https://neps.academy/br/exercise/650
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int c = 1;
  while (1) {

    int n;
    cin >> n;
    if (!n)
      return 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      v[i] = x - y;
    }

    int sg = INT_MIN, sl = 0;
    int a = 0, b = 0, j = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] > v[i] + sl) {
        j = i;
      }
      sl = max(sl + v[i], v[i]);

      if (sl > sg) {
        sg = sl;
        a = j + 1;
        b = i + 1;
      } else if (sl == sg && b - a < i - j) {
        a = j + 1;
        b = i + 1;
      }
    }
    cout << "Teste " << c++ << '\n';
    if (sg <= 0)
      cout << "nenhum" << endl;
    else
      cout << a << " " << b << endl;
  }
  return 0;
}

// -1, 6