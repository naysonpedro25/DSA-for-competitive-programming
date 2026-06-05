#include <iostream>
#include <vector>

using namespace std;

int bs(const vector<int> &v, int n, int x) {

  if (v.empty() || x > v[n - 1] || x < v[0])
    return -1;

  int ini = 0, fim = n - 1, meio;

  while (ini <= fim) {
    meio = (ini + fim) / 2;

    if (v[meio] == x)
      return meio;
    if (v[meio] > x) {
      fim = meio - 1;
    } else
      ini = meio + 1;
  }
  return -1;
}

int main() {

  int n, q;
  cin >> n >> q;

  vector<int> v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < q; i++) {
    int qy;
    cin >> qy;
    cout << bs(v, n, qy) << "\n";
  }

  return 0;
}