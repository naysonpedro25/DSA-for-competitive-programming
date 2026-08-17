#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int v[] = {1, 3, 7, 9};
  int n = sizeof(v);
  int p[n + 1];
  p[0] = 0;

  for (int i = 0; i < 3; i++) {
    p[i + 1] = p[i] + v[i];
  }

  cout << n;
  return 0;
}
