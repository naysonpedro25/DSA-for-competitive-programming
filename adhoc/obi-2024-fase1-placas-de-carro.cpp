#include "bits/stdc++.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;
// https://neps.academy/br/exercise/2715
bool isBr(string &s) {

  if (s.size() != 8)
    return false;

  for (int i = 0; i < 3; i++) {
    if (!isupper(s[i]))
      return false;
  }

  if (s[3] != '-')
    return false;

  for (int i = 4; i < 8; i++) {
    if (!isdigit(s[i]))
      return false;
  }

  return true;
}

bool isMerc(string &s) {
  if (s.size() != 7)
    return false;

  for (int i = 0; i < 3; i++) {
    if (!isupper(s[i]))
      return false;
  }

  if (!isdigit(s[3]))
    return false;

  if (!isupper(s[4]))
    return false;

  if (!isdigit(s[5]))
    return false;
  if (!isdigit(s[6]))
    return false;

  return true;
}
int main() {

  string p;
  cin >> p;

  if (isBr(p))
    cout << 1;
  else if (isMerc(p))
    cout << 2;
  else
    cout << 0;

  return 0;
}