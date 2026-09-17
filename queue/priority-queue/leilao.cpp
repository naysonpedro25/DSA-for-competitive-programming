#include <bits/stdc++.h>
#include <functional>
using namespace std;
//https://neps.academy/br/exercise/2322
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  priority_queue<pair<int, int>, vector<pair<int,int>>,greater<>> q;
  vector<string> nomes(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> nomes[i] >> a;
    q.push({-a, i});
  }

  cout << nomes[q.top().second] << '\n' << -q.top().first;

  return 0;
}
