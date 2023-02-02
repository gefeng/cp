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
    
    string S, T;
    cin >> S >> T;

    if(S == T) {
        cout << 0 << '\n';
        return;
    }

    int x = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] != T[i]) {
            x += 1;
        }
    }

    vector<LL> inv(N + 1, 0LL);
    for(int i = 1; i <= N; i++) {
        inv[i] = q_pow(i, MOD - 2LL);
    }

    vector<LL> f(N + 2, 0LL);
    for(int i = N; i > 0; i--) {
        f[i] = (N * inv[i] % MOD + ((N - i) * inv[i] % MOD) * f[i + 1] % MOD) % MOD;
    }

    LL ans = 0LL;
    for(int i = x; i > 0; i--) {
        ans += f[i];
        ans %= MOD;
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
