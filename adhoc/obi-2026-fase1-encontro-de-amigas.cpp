// https://neps.academy/br/exercise/3881
#include <bits/stdc++.h>
#include <cstddef>
#include <utility>
using namespace std;

pair<int, int> hj(pair<int, int> a, pair<int, int> b) {
  if (a.second >= b.first && a.first <= b.second) {
    return {max(b.first, a.first), min(b.second, a.second)};
  }
  return {-1, -1};
}

int main() {
  int a1, a2, b1, b2, c1, c2;
  cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

  bool haveJ = false;

  pair<int, int> ab = hj({a1, a2}, {b1, b2});
  if (ab.first == -1) {
    cout << 0;
    return 0;
  }

  pair<int, int> abc = hj(ab, {c1, c2});

  if (abc.first == -1) {
    cout << 0;
    return 0;
  }

  cout << ( abc.second - abc.first + 1);
}
