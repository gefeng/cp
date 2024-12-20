#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

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

    if(N == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int64_t> dp(K + 1, 0);
    dp[0] = 1; 
    
    int64_t p = ((int64_t)1 - (((int64_t)2 * (N - 1) % MOD) * q_pow((int64_t)N * N % MOD, MOD - 2) % MOD) + MOD) % MOD;
    int64_t q = (int64_t)2 * q_pow((int64_t)N * N % MOD, MOD - 2) % MOD;
    for(int i = 1; i <= K; i++) {
        dp[i] = (dp[i - 1] * p % MOD) + ((((int64_t)1 - dp[i - 1] + MOD) % MOD) * q % MOD);
        dp[i] %= MOD;
    }

    int64_t ans = dp[K] + ((((1 - dp[K] + MOD) % MOD) * q_pow(N - 1, MOD - 2) % MOD) * ((((int64_t)N + 2) * (N - 1) / 2) % MOD) % MOD);
    ans %= MOD;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
