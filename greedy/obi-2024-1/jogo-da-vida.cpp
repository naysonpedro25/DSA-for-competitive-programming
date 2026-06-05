#include "bits/stdc++.h"
#include <vector>
using namespace std;
//https://neps.academy/br/exercise/2714
int main() {

  int n, q;
  cin >> n >> q;

  vector<vector<int>> m(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    string l;
    cin >> l;
    for (int j = 0; j < n; j++) {
      m[i][j] = l[j] - '0';
    }
  }

  while (q--) {
  vector<vector<int>> mods(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int countV = 0;

      if (i - 1 >= 0 && m[i - 1][j] == 1)
        countV++;
      if (j - 1 >= 0 && m[i][j - 1] == 1)
        countV++;

      if (i + 1 < n && m[i + 1][j] == 1)
        countV++;
      if (j + 1 < n && m[i][j + 1] == 1)
        countV++;

      if (i - 1 >= 0 && j - 1 >= 0 && m[i - 1][j - 1] == 1)
        countV++;
      if (i - 1 >= 0 && j + 1 < n && m[i - 1][j + 1] == 1)
        countV++;
      if (i + 1 < n && j - 1 >= 0 && m[i + 1][j - 1] == 1)
        countV++;
      if (i + 1 < n && j + 1 < n && m[i + 1][j + 1] == 1)
        countV++;

      if (m[i][j] == 0) {
        if (countV == 3)
          mods[i][j] = 1;
      } else {
        if (countV == 3 || countV == 2)
          mods[i][j] = 1;
      }
    }
  }
  m = mods;
  }
  cout << "\n";

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << m[i][j];
    }
    cout << "\n";
  }

  return 0;
}