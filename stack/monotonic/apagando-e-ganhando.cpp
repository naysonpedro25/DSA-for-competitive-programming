#include <iostream>

// https://www.thehuxley.com/problem/653?locale=pt_BR
// e
// https://neps.academy/br/exercise/292
using namespace std;

int main() {

  while (1) {
    int n, d;
    cin >> n >> d;
    if (n == 0 & d == 0)
      return 0;

    string num, ms = "";
    cin >> num;

    for (int i = 0; i < n; i++) {
      while (!ms.empty() && d > 0 && ms.back() - '0' < num[i] - '0') {
        ms.pop_back();
        d--;
      }
      ms.push_back(num[i]);
    }

    while (d > 0) {
      ms.pop_back();
      d--;
    }

    cout << ms << "\n";
  }
  return 0;
}
