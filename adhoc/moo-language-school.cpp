#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, k, res = 0, cnt = 0;
    cin >> n >> k;
    string v;
    cin >> v;

    for(int i = 0; i < n;i+=k){
        int cnt=  0;
        for(int j = i; j < i+k;j++){
            if(v[j] == '0') cnt++;
        }
        if(cnt == 0){
            res++;
        }

    }
    cout << res << "\n";
  }
  return 0;
}
