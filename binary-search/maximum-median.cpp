#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/1201/C
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  long long k;
  cin >> n >> k;

  vector<int> v(n);
  for (int &i : v)
    cin >> i;

  sort(v.begin(), v.end());

  long long l = 0, r = 1e18+10, m, res = r;



  while (l <= r) {
    m = (l + r) / 2;
    long long s = 0;
    for(int i = (n/2); i < n; i++){
      s += (m - v[i]);
      if(s > k) break;
    }

    if(s > k){
      r = m -1;
    }else{
      res = m;
      l = m + 1;
    }

  }

  cout << res;

  return 0;
}

// 1 1000000000
// 1000000000
// 2000000000