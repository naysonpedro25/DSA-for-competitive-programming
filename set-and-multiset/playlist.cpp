#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);

  for (int &i : v)
    cin >> i;

  int res = 0;
  multiset<int> st;
  int j = 0;
  for (int i = 0; i < n; i++) {
    st.insert(v[i]);
    while (j < i && !st.empty() && st.count(v[i]) > 1) {
      st.erase(st.find(v[j]));
      j++;
    }
    res = max(i - j + 1, res);
  }
  cout << res;

  return 0;
}
/* 10
3 3 3 3 5 1 5 1 1 4 */