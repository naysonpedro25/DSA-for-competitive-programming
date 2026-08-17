#include <bits/stdc++.h>
using namespace std;
//https://neps.academy/br/exercise/2792
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int k, n;
  cin >> k >> n;

  unordered_set<char> st;
  string alf;
  cin >> alf;
  for (char c : alf) {
    st.insert(c);
  }

  string msg;
  cin >> msg;

  for (char c : msg) {
    if (!st.count(c)) {
      cout << 'N';
      return 0;
    }
  }

  cout << 'S';

  return 0;
}
