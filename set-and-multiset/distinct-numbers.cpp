#include <bits/stdc++.h>

using namespace std;
// https://cses.fi/problemset/task/1621
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  set<int> s; // é melhor que o unordered por conta da inserção
  while (n--) {
    int a;
    cin >> a;
    s.insert(a);
  }

  cout << s.size();

  return 0;
}
