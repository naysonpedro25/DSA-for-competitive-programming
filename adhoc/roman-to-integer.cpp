// https://leetcode.com/problems/roman-to-integer/
#include "bits/stdc++.h"
#include <vector>

using namespace std;

#define LL long long

int main() {
  string s = "III";
  unordered_map<char, int> mp;
  mp['I'] = 1;
  mp['V'] = 5;
  mp['X'] = 10;
  mp['L'] = 50;
  mp['C'] = 100;
  mp['D'] = 500;
  mp['M'] = 1000;

  int res = 0;

  for (int i = s.size() - 1; i >= 0; i--) {
    if (i < s.size() - 1 && mp[s[i]] < mp[s[i + 1]])
      res -= mp[s[i]];
    else
      res += mp[s[i]];
  }

  cout << res;

  return 0;
}
