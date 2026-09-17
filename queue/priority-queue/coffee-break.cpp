#include <bits/stdc++.h>
#include <functional>
using namespace std;
//https://codeforces.com/problemset/problem/1041/C
struct A {
  int ini, fim, id;
  bool operator<(const A &other) const { return ini < other.ini; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, d;
  cin >> n >> m >> d;

  vector<A> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].ini;
    v[i].id = i;
    v[i].fim = d + v[i].ini + 1;
  }

  sort(v.begin(), v.end());

  int count = 0;
  vector<int> res(n);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

  for (int i = 0; i < n; i++) {
    int dia = -1;

    if (!q.empty() && v[i].ini >= q.top().first) {
      dia = q.top().second;
      q.pop();
    }

    if (dia == -1) {
      count++;
      dia = count;
    }

    res[v[i].id] = dia;
    q.push({v[i].fim, dia});
  }

  cout << count << '\n';

  for (int i : res)
    cout << i << ' ';

  return 0;
}
