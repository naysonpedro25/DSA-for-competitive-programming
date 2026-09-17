#include <bits/stdc++.h>
#include <functional>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
// https://neps.academy/br/exercise/253
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;
  vector<string> nomes(n);
  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    cin >> nomes[i];
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end(), [](pii &a, pii &b) { return a.first > b.first; });

  queue<pii> q;

  vector<priority_queue<string, vector<string>, greater<>>> res(t);
  for (int i = 0; i < t; i++) {
    q.push({v[i].first, i});
    res[i].push(nomes[v[i].second]);
  }

  for (int i = t; i < n; i++) {
    auto [soma, time] = q.front();
    q.pop();
    soma += v[i].first;
    res[time].push(nomes[v[i].second]);

    q.push({soma, time});
  }

  for (int i = 0; i < t; i++) {
    cout << "Time " << i + 1 << endl;
    while (!res[i].empty()) {
      cout << res[i].top() << endl;
      res[i].pop();
    }
    cout << endl;
  }

  return 0;
}
