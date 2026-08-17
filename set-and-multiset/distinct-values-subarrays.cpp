#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);

  for (int &i : v)
    cin >> i;

  set<int> st;

  int j = 0;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    while (!st.empty() && st.count(v[i])) {
      st.erase(v[j]);
      j++;
    }
    st.insert(v[i]);

    res += (int)st.size();
  }
  cout << res;
  return 0;
}

/*
HTTP client/server em Java
connection pooling
timeouts
keep-alive
blocking vs non-blocking I/O
threads / thread pools
concorrência
*/