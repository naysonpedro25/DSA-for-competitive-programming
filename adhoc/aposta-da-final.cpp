#include <bits/stdc++.h>
using namespace std;
//https://neps.academy/br/exercise/2855
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;
  int x, y;
  cin >> x >> y;

  if (a * x > b * y)
    cout << 1;
  else if (a * x > b * y)
    cout << 0;
  else
    cout << 2;

  return 0;
}
