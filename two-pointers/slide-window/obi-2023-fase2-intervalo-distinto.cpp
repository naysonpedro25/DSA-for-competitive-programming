#include <bits/stdc++.h>
#include <vector>
using namespace std;
// https://neps.academy/br/exercise/2438
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);
  for (int &i : v) {
    cin >> i;
  }
  int j = 0, maxInter = 0;
  set<int> st;
  for (int i = 0; i < n; i++) {
    while (j < n && st.count(v[i])) {
      st.erase(v[j]);
      j++;
    }
    st.insert(v[i]);
    maxInter = max(maxInter, i - j + 1);
  }
  cout << maxInter;

  return 0;
}
