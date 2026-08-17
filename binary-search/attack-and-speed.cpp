#include <bits/stdc++.h>

using namespace std;

#define ll long long
int main() {
    
    ll a,s,k,x,y;
    cin >> a >> s >> k  >> x >> y;
    
    ll l = 0, r = k;
    ll res = -1;
    
    while(l <= r){
        ll mid = (l  + r)/ 2;
        
        ll cx = (a + x * mid);
        ll cy = (s + y * (k - mid));
        
        if(cx > cy){
            r = mid -1;
        }else if(cx < cy){
            l = mid +1;
        }else {
            res = mid;
            break;
        }
    }
    cout << res;
    return 0;
}
//https://csacademy.com/contest/archive/task/attack-and-speed/