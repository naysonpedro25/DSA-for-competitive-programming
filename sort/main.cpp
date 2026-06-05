#include <iostream>
#include <vector>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int> > m(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }


    int count = 0;


    for (int k = 0; k <2; k++) {
        for (int l = 0; l < n; l++) {

            m[k][l] =1;
            bool a = false;
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (m[i][j] == 0) {
                        if (m[i][j + 1] == 0 || m[i + 1][j] ==0) {
                            a = true;
                        }
                    }
                }
            }


            if (!a) {
                count++;
            }
            m[k][l] =0;
        }
    }
    cout << count << endl;
    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << m[i][j] << " g";
    //     }
    // }

    return 0;
}
