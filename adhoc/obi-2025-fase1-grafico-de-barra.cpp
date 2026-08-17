#include "bits/stdc++.h"
#include <algorithm>
#include <vector>

using namespace std;
//https://neps.academy/br/exercise/3126
int main() {

  int n;
  cin >> n;
  vector<int> v(n);
  int maxE = -1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    maxE = max(maxE, v[i]);
  }

  vector<vector<int>> res(maxE, vector<int>(n, 0));

  for (int j = 0; j < n; j++) {
    
    for (int i = maxE - 1; i >= 0; i--) {
      if (v[j] > 0) {
        res[i][j] = 1;
      } else
        res[i][j] = 0;
      v[j]--;
    }
  }
  for (int i = 0; i < maxE; i++) {
    for (int j = 0; j < n; j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }

  cout << maxE;
}
