#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)6e18;

void run_case() {
    LL N, X;
    cin >> N >> X;

    if(N == X) {
        cout << N << '\n';
        return;
    }

    if(N < X) {
        cout << -1 << '\n';
        return;
    }

    array<int, 64> b1{0};
    array<int, 64> b2{0};
    
    for(int i = 0; i < 64; i++) {
        if(N & (1LL << i)) {
            b1[i] = 1;
        }

        if(X & (1LL << i)) {
            b2[i] = 1;
        }
    }

    int j = -1;
    for(int i = 0; i < 64; i++) {
        if(b2[i] == 1) {
            j = i;
            break;
        }
    } 

    LL ans = 0LL;
    if(j == -1) {
        for(int i = 63; i >= 0; i--) {
            if(b1[i] == 1) {
                ans = 1LL << (i + 1);
                break;
            }
        }
    } else {
        for(int i = 63; i >= j; i--) {
            if(b1[i] != b2[i]) {
                cout << -1 << '\n';
                return;
            }
        }

        for(int i = j - 1; i >= 0; i--) {
            if(b1[i] == 1) {
                if(i + 1 == j) {
                    cout << -1 << '\n';
                    return;
                } else {
                    b1[i + 1] = 1;
                    for(int k = i; k >= 0; k--) {
                        b1[k] = 0;
                    }
                    break;
                }
            } 
        }

        for(int i = 0; i < 64; i++) {
            if(b1[i] == 1) {
                ans |= 1LL << i;
            }
        }
    }

    cout << ans << '\n';
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
