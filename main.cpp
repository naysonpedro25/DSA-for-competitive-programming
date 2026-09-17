#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define f first
#define s second

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, t;
  cin >> n >> t;

  vector<pii> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].f;
    v[i].s = i;
  }

  sort(v.begin(), v.end());

  for (int i = 0, j = n - 1; i < j;) {
    int p1 = v[i].f + v[j].f, p2 = 0;

    for (int k = i + 1, l = j - 1; k < l;) {
      p2 = v[k].f + v[l].f;
      if (p1 + v[k].f + v[l].f > t) {
        l--;
      } else if (p1 + v[k].f + v[l].f < t) {
        k++;
      } else {
        cout << v[i].s + 1 << " " << v[k].s + 1 << " " << v[l].s + 1 << " "
             << v[j].s + 1;
        return 0;
      }
    }

    if (p2 + v[i].f + v[i].f > t) {
      j--;
    } else if (p2 + v[i].f + v[i].f > t) {
      i++;
    }
  }

  cout << "IMPOSSIBLE";

  return 0;
}
