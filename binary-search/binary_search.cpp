#include <iostream>

using namespace std;

int bs(int v[], int n, int x) {
  int ini = 0, fim = n - 1, meio, asn = -1;
  while (ini <= fim) {
    meio = (ini + fim) / 2;
    if (v[meio] >= x) {
      asn = v[meio];
      fim = meio - 1;
    } else
      ini = meio + 1;
  }
  return asn;
}

int main() {

  int list[10] = {1, 2, 3, 4, 5, 6, 7, 10, 34, 56};

  int v = bs(list, 10, 55);
  cout << v;
  return 0;
}