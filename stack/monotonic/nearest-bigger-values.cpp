#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n), res(n);
  stack<int> st; // guarda índices

  for (int i = 0; i < n; i++)
    cin >> v[i];

  for (int i = n - 1; i >= 0; i--) {

    while (!st.empty() && v[st.top()] <= v[i])
      st.pop();

    if (st.empty())
      res[i] = 0; // ou -1, dependendo do problema
    else
      res[i] = st.top() + 1; // posição (1-based)

    st.push(i);
  }

  for (int i = 0; i < n; i++)
    cout << res[i] << " ";
}