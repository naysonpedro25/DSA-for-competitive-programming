#include "bits/stdc++.h"
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iterator>
#include <vector>

using namespace std;

// https://usaco.org/index.php?page=viewproblem2&cpid=597
//  satanic question

#define ll long long int
ll n;
vector<ll> v;

//= {2, 6, 16, 20, 22};

bool verifyRight(ll iOfFirstBale, ll r) { // O nlog n

  ll currentI = iOfFirstBale;
  ll currentPosi = v[iOfFirstBale];
  ll currentR = r;

  while (currentR > 0) {

    if (currentI == n - 1) {
      return true;
    }
    auto it = upper_bound(v.begin(), v.end(), currentPosi + currentR);
    --it;
    ll nextI = distance(v.begin(), it);

    if (nextI == currentI) {
      return false;
    }

    currentI = nextI;

    currentPosi = v[currentI];
    currentR -= 2;
  }

  return currentI == n - 1;
}

bool verifyLeft(ll iOfFirstBale, ll r) { // O nlog n

  ll currentI = iOfFirstBale;
  ll currentPosi = v[iOfFirstBale];
  ll currentR = r;

  while (currentR > 0) {

    if (currentI == 0) {
      return true;
    }

    auto it = lower_bound(v.begin(), v.end(), currentPosi - currentR);

    ll nextI = distance(v.begin(), it);

    if (nextI == currentI) {
      return false;
    }

    currentI = nextI;

    currentPosi = v[currentI];

    currentR -= 2;
  }

  return currentI == 0;
}

bool check(ll R) { // On (log n)^2

  if (v[n - 1] - v[0] <= 2 * R)
    return true;

  ll l = 0, r = n - 1, maioL = 0;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    if (m == 0 || verifyLeft(m, R - 2)) {
      maioL = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  l = 0, r = n - 1;
  ll menorR = n - 1;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    if (mid == n - 1 || verifyRight(mid, R - 2)) {
      menorR = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return (v[menorR] - v[maioL] <= 2 * R);
}

int main() { // O log(max_i) * n * (log n) ^2

  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i] *= 2;
  }
  sort(v.begin(), v.end());
  ll l = 0, r = v[n - 1] - v[0];
  ll res = r;

  while (l <= r) { 
    ll m = l + (r - l) / 2;

    if (check(m)) {
      res = m;
      r = m - 1;
    } else
      l = m + 1;
  }

  cout << fixed << setprecision(1) << (double)res / 2.0 << '\n';
  return 0;
}

// 0 1 2  3  4
// 1 3 8 10 11