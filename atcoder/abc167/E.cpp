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
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<LL> p(N + 1, 1LL);
    for(int i = 1; i <= N; i++) {
        p[i] = p[i - 1] * (M - 1) % MOD;
    }

    vector<LL> fact(N + 1, 1LL);
    vector<LL> invf(N + 1, 1LL);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 1; i <= N; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }

    LL ans = 0LL;
    for(int i = 0; i <= K; i++) {
        ans += (((M * p[N - i - 1] % MOD) * fact[N - 1] % MOD) * invf[N - i - 1] % MOD) * invf[i] % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
