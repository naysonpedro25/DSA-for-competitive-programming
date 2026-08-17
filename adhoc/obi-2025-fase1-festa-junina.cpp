#include "bits/stdc++.h"
#include <algorithm>
#include <vector>
//https://neps.academy/br/exercise/3124

using namespace std;

int main() {
  int e, s, l;
  cin >> e >> s >> l;
  cout << (abs(e - s) + abs(s - l) + abs(l - e));
}
