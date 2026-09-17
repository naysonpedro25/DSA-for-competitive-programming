#include <bits/stdc++.h>
#include <string>
using namespace std;
// https://neps.academy/br/exercise/390
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  char m[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }
  int sum = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < n; j++) {
        if (m[i][j] == 'o') {
          sum++;
          mx = max(mx, sum);
        } else if (m[i][j] == 'A') {
          sum = 0;
        }
      }
    } else {
      for (int j = n - 1; j >= 0; j--) {
        if (m[i][j] == 'o') {
          sum++;
          mx = max(mx, sum);
        } else if (m[i][j] == 'A') {
          sum = 0;
        }
      }
    }
  }
  cout << mx;

  return 0;
}
