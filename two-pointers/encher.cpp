#include <bits/stdc++.h>

using namespace std;

int main() {
  // Seu código vai aqui
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  int comp = v[0] + v[n - 1];
  int l = 0, r = n - 1;
  bool isValid = true;
  while (l <= r) {
    if (v[l] + v[r] != comp) {
      isValid = false;
      break;
    }
    l++;
    r--;
  }
  cout << (isValid ? "S" : "N");
  return 0;
}
//https://neps.academy/br/exercise/892