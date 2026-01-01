#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
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
    int N, K;
    std::cin >> N >> K;

    int64_t ans = 0;
    if(K >= N) {
        ans = 1;
        for(int i = 0; i < N; i++) {
            ans *= 2;
            ans %= MOD;
        }        
    } else {
        std::vector<int64_t> fact(N + 1, 1);
        std::vector<int64_t> invf(N + 1, 1);
        for(int i = 1; i <= N; i++) {
            fact[i] = fact[i - 1] * i % MOD;
            invf[i] = q_pow(fact[i], MOD - 2);
        }

        for(int i = 0; i <= K; i++) {
            ans += (fact[N] * invf[i] % MOD) * invf[N - i] % MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
