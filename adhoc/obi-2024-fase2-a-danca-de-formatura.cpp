#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
// https://neps.academy/br/exercise/2794
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, p;
  cin >> n >> m >> p;
  vector<vector<int>> mt(n, vector<int>(m, 0));

  vector<int> lin(n), col(m);
  int posi = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mt[i][j] = posi++;
      col[j] = j;
    }
    lin[i] = i;
  }

  while (p--) {
    char c;
    int a, b;
    cin >> c >> a >> b;
    --a;
    --b;
    if (c == 'C') {
      swap(col[a], col[b]);
    } else
      swap(lin[a], lin[b]);
  }

  for (int i : lin) {
    for (int j : col) {
      cout << mt[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}
