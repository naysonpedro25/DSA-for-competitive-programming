#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << "0 0\n";
        return 0;
    }

    long long k;
    
    if (n % 3 == 1) {
        k = (n + 2) / 3;
        cout << 2 * k - 1 << ' ' << -k + 1 << '\n';
    }
    else if (n % 3 == 2) {
        k = (n + 1) / 3;
        cout << k << ' ' << k << '\n';
    }
    else {
        k = n / 3;
        cout << -2 * k << ' ' << -k << '\n';
    }
}