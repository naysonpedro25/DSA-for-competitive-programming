#include "bits/stdc++.h"
//https://neps.academy/br/exercise/3130
using namespace std;
int main() {

  string n;
  cin >> n;
  int ni = stoi(n);
  int count = 0;
  while (ni != 0) {
    int m = *max_element(n.begin(), n.end()) - '0';
    ni -= m;
    n = to_string(ni);
    count++;
  }
  cout << count;

  return 0;
}