#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    for(int c = 0; c < 2; c++) {
        bool ok = true;
        vector<int> v(26, -1);
        for(int i = 0; i < N; i++, c ^= 1) {
            if(v[S[i] - 'a'] == -1) {
                v[S[i] - 'a'] = c; 
            } else {
                if(v[S[i] - 'a'] != c) {
                    ok = false;
                    break;
                }
            }
        }

        if(ok) {
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}
