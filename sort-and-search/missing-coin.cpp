#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> v(n);

  for (int &i : v)
    cin >> i;
  sort(v.begin(), v.end());

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] > sum + 1)
      break;
    sum += v[i];
  }
  cout << sum + 1;

  return 0;
}
