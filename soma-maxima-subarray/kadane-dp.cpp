// https://leetcode.com/problems/maximum-subarray/
#include "bits/stdc++.h"
#include <algorithm>
#include <climits>

using namespace std;

int main() {
  // vale para valores negativos
  vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n = v.size();

  int somaMax = INT_MIN;
  int somaLocal = v[0];
  for (int i = 1; i < n; i++) {
    somaLocal = max(v[i], somaLocal + v[i]);

    somaMax = max(somaLocal, somaMax);
  }

  cout << somaMax;

  return 0;
}