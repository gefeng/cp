#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = 998244353LL;

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
    std::cin >> N >> M >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<LL> fact(N + 1, 1LL);
    std::vector<LL> invf(N + 1, 1LL);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    for(int i = 1; i <= N; i++) {
        invf[i] = q_pow(fact[i], MOD - 2LL);
    }

    LL ans = 0LL;
    for(int i = 1; i <= M; i++) {
        int zero = 0;
        int need = N - K + 1;
        
        for(int x : A) {
            if(x >= i) {
                need -= 1;
            }
            if(x == 0) {
                zero += 1;
            }
        }

        if(need <= 0) {
            ans += 1LL;
            ans %= MOD;
            continue;
        }

        if(zero < need) {
            continue;
        }

        LL p = 1LL * (M - i + 1) * q_pow(M, MOD - 2LL) % MOD;
        LL q = ((1LL - p) + MOD) % MOD;
        std::vector<LL> save_p(zero + 1, 1);
        std::vector<LL> save_q(zero + 1, 1);
        for(int j = 1; j <= zero; j++) {
            save_p[j] = save_p[j - 1] * p % MOD;
            save_q[j] = save_q[j - 1] * q % MOD;
        }
        
        for(int j = need; j <= zero; j++) {
            LL binom = (fact[zero] * invf[j] % MOD) * invf[zero - j] % MOD;
            ans += (binom * save_p[j] % MOD) * save_q[zero - j] % MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
