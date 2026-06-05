#include <iostream>
#include <stack>
#include <vector>
// https://cses.fi/problemset/task/1645

using namespace std;

int main() {

  int n;
  cin >> n;
  vector<int> v(n);

  stack<int> ms;
  for (int i = 0; i < n; i++)
    cin >> v[i];

  for (int i = 0; i < n; i++) {

    while (!ms.empty() && v[ms.top()] >= v[i])
      ms.pop();

    if (ms.empty())
      cout << "0 ";
    else
      cout << ms.top() + 1 << " ";

    ms.push(i);
  }

  return 0;
}
