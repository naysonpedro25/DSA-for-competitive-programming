#include "bits/stdc++.h"
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define ll long long
//https://codeforces.com/problemset/problem/545/D
int main() {

  ll n;
  cin >> n;

  deque<ll> v(n);
  for (ll i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  ll soma = 0;
  ll res = 0;
  for (ll i = 0; i < n; i++) {

    if (soma <= v[i]) {
      res++;
      soma += v[i];
    }
  }

  cout << res;
  return 0;
}

// 10
// 13 2 5 55 21 34 1 8 1 3
// 1 1 2 3 5 8  13 21 34 55
// 1 2 3 5 15