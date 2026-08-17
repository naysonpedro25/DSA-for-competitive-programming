// https://cses.fi/problemset/task/1164
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<pair<pair<int, int>, int>> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i;
  }

  sort(v.begin(), v.end());
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> exit;

  vector<int> rooms(n);

  int ctn = 0;

  for (int i = 0; i < n; i++) {
    int r = -1;
    if (!exit.empty() && v[i].first.first > exit.top().first) {
      r = exit.top().second;
      exit.pop();
    }

    if (r == -1) {
      ctn++;
      rooms[v[i].second] = ctn;
      exit.push({v[i].first.second, ctn});
    } else {
      rooms[v[i].second] = r;
      exit.push({v[i].first.second, r});
    }
  }
  cout << ctn << endl;

  for (int i : rooms)
    cout << i << " ";
  return 0;
}
