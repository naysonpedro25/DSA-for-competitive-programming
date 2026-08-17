#include "bits/stdc++.h"
#include <algorithm>
#include <vector>
// https://neps.academy/br/exercise/3125

using namespace std;

int main() {
  int a, b, c;
  int d;

  cin >> a >> b >> c >> d;
  int maxNum = c / d;
  bool res = false;
  while (maxNum) {
    int totalCaf = maxNum * d;

    int dif = c - totalCaf;
    if (dif >= a && dif <= b) {
      res = true;
      break;
    }
    maxNum--;
  }

  if (res)
    cout << "S";
  else
    cout << "N";
}
