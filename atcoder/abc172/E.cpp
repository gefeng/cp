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
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<LL> fact(M + 1, 1LL);
    vector<LL> invf(M + 1, 1LL);

    for(int i = 2; i <= M; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 2; i <= M; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }

    LL ans = (fact[M] * invf[M - N] % MOD) * (fact[M] * invf[M - N] % MOD) % MOD;
    for(int i = 1; i <= N; i++) {
        LL cnt = ((fact[N] * invf[N - i] % MOD) * invf[i] % MOD) * (fact[M] * invf[M - i] % MOD);
        cnt %= MOD;

        cnt *= (fact[M - i] * invf[M - N] % MOD) * (fact[M - i] * invf[M - N] % MOD) % MOD;
        cnt %= MOD;

        if(i & 1) {
            ans -= cnt;
            ans += MOD;
            ans %= MOD;
        } else {
            ans += cnt;
            ans %= MOD;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
