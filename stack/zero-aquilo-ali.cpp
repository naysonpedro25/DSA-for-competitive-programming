#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//https://neps.academy/br/exercise/1749
int main() {
  // Seu código vai aqui
  int n;
  cin >> n;
  stack<int> ms;
  while (n--) {
    int v;
    cin >> v;
    if (v != 0)
      ms.push(v);
    else if (!ms.empty())
      ms.pop();
  }
  int res = 0;
  while (!ms.empty()) {
    res += ms.top();
    ms.pop();
  }
  cout << res;
  return 0;
}
