
#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>
using namespace std;
struct event {
  int tmp, type, id; // tempo em que acontece o evento e tipo do evento (1 ou 2)
  event(int t, int tp, int i) {
    tmp = t;
    type = tp;
    id = i;
  }
  bool operator<(event e) {
    if (tmp == e.tmp)
      return type <
             e.type; // isso é importante, para esse problema, o poderia ser
                     // diminuir (evento 2) antes de aumentar (evento 1)
    return tmp < e.tmp;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<event> v;
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    int e, s;
    cin >> e >> s;
    v.push_back(event(e, 1, i));
    v.push_back(event(s, 2, i));
  }

  sort(v.begin(), v.end());
  int room = 0;
  int res[n];
  // sweep
  for (event e : v) {
    if (e.type == 1) {
      int roomAlloc;
      if (!q.empty()) {
        roomAlloc = q.top();
        q.pop();
      } else {
        room++;
        roomAlloc = room;
      }
      res[e.id] = roomAlloc;
    } else {
      q.push(res[e.id]);
    }
  }
  cout << room << '\n';
  for (int i : res) {
    cout << i << ' ';
  }

  return 0;
}
