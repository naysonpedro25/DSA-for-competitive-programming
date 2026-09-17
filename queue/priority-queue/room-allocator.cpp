// // https://cses.fi/problemset/task/1164
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;

struct Cliente {
  int id, entrada, saida;
  bool operator<(const Cliente &other) const {
    return entrada < other.entrada;
  };
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<Cliente> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].entrada >> v[i].saida;
    v[i].id = i;
  }

  sort(v.begin(), v.end());

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  vector<int> res(n);
  int count = 0;

  for (int i = 0; i < n; i++) {
    int room = -1; // número da sala começa nulo

    // se para o próximo cliente existe alguma sala vaga quando ele entra
    // tiro da fila, pego número e sigo

    if (!q.empty() && v[i].entrada > q.top().first) {
      room = q.top().second;
      q.pop();
    }
    // se nenhuma sala foi reaproveitada no if anterior, aloco uma nova sala
    if (room == -1) {
      count++;
      room = count; // a partir da contagem global de sala
    }

    // no fim, para o cliente atual alocado, guardo em qual sala ele ficou
    res[v[i].id] = room;
    // e coloco na fila quando ele sai e a sala que ele está
    q.push({v[i].saida, room});
  }

  cout << count << endl;
  for (int i : res) {
    cout << i << ' ';
  }

  return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

//   int n;
//   cin >> n;
//   vector<pair<pair<int, int>, int>> v(n);

//   for (int i = 0; i < n; i++) {
//     cin >> v[i].first.first >> v[i].first.second;
//     v[i].second = i;
//   }

//   sort(v.begin(), v.end());
//   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> exit;

//   vector<int> rooms(n);

//   int ctn = 0;

//   for (int i = 0; i < n; i++) {
//     int r = -1;
//     if (!exit.empty() && v[i].first.first > exit.top().first) {
//       r = exit.top().second;
//       exit.pop();
//     }

//     if (r == -1) {
//       ctn++;
//       rooms[v[i].second] = ctn;
//       exit.push({v[i].first.second, ctn});
//     } else {
//       rooms[v[i].second] = r;
//       exit.push({v[i].first.second, r});
//     }
//   }
//   cout << ctn << endl;

//   for (int i : rooms)
//     cout << i << " ";
//   return 0;
// }
