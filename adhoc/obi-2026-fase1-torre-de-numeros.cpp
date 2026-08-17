// https://neps.academy/br/exercise/3884
#include <algorithm>
#include <bits/stdc++.h>
#include <deque>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void zeroEs(string &s) { // aqui, era só usar um simples while(s.size() < 4) s =
                         // '0' + s; Ou ainda só um     s.insert(s.begin(), 4 -
                         // s.size(), '0');

  // deque<char> ms;
  // ms.assign(s.begin(), s.end());

  // while (ms.size() < 4) {
  //   ms.push_front('0');
  // }

  // s.assign(ms.begin(), ms.end());

  s.insert(s.begin(), 4 - s.size(), '0');
}

int main() {

  string toSort;
  cin >> toSort;

  zeroEs(toSort);

  int n = stoi(toSort);
  vector<int> t;

  t.push_back(n);

  unordered_map<int, bool>
      m; // aq, nem hash precisa, era só usar um vector de vis
  m[n] = 1;

  while (1) {

    sort(toSort.begin(), toSort.end());
    int x1 = stoi(toSort);
    reverse(toSort.begin(), toSort.end());
    int x2 = stoi(toSort);

    n = x2 - x1;
    toSort = to_string(n);
    zeroEs(toSort);

    if (m[n]) {
      // cout << "achado";
      break;
    }

    t.push_back(n);
    m[n] = 1;
  }

  for (int i : t)
    cout << i << '\n';

  return 0;
}
