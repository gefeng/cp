#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

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

    LL ans = 0LL;
    
    LL x = ((1LL * (N - 1) * N % MOD) * (2LL * N - 1LL) % MOD) * q_pow(3LL, MOD - 2) % MOD;
    LL y = (1LL * N * (N - 1LL) % MOD) * q_pow(2LL, MOD - 2);
    LL z = 1LL * N * N % MOD;
    
    ans = 2022LL * ((x + y + z) % MOD) % MOD;
    
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
