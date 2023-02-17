#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

LL q_pow(LL x, LL y) {
    LL res = 1LL;
    while(y) {
        if(y & 1LL) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1LL;
    }
    return res;
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for(int i = 0; i < N; i += 3) {
        sort(A.begin() + i, A.begin() + i + 3);
    }

    LL ans = 1LL;
    for(int i = 0; i < N; i += 6) {
        array<LL, 2> m1{0LL};
        for(int j = 0; j < 2; j++) {
            //cout << i + j * 3 + 2 << '\n';
            int a = A[i + j * 3];
            int b = A[i + j * 3 + 1];
            int c = A[i + j * 3 + 2];
            LL x = 0LL;
            if(a == b && b == c) {
                x = 3LL;
            } else {
                if(a != b && a != c && b != c) {
                    x = 1LL;
                } else {
                    if(b == c) {
                        x = 1LL;
                    } else {
                        x = 2LL;
                    }
                }
            }
            m1[j] = x;
        }

        LL tot = (m1[0] * m1[1] % MOD);
        ans *= tot;
        ans %= MOD;
    }

    int n = N / 3;
    vector<LL> fact(n + 1, 1LL);
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    
    vector<LL> invf(n + 1, 1LL);
    for(int i = 1; i <= n; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }
    
    ans *= fact[n];
    ans %= MOD;
    ans *= invf[n / 2] * invf[n / 2] % MOD;
    ans %= MOD;

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}
