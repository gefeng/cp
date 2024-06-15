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
    int K;
    std::cin >> K;

    std::array<int, 26> A = {};
    int max_len = 0;
    for(int i = 0; i < 26; i++) {
        std::cin >> A[i];
        max_len += A[i];
    }

    K = std::min(K, max_len);

    std::vector<int64_t> fact(K + 1, 1);
    std::vector<int64_t> invf(K + 1, 1);
    for(int i = 1; i <= K; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    std::vector<int64_t> dp(K + 1, 0);
    dp[K] = 1;

    for(int i = 0; i < 26; i++) {
        if(!A[i]) {
            continue;
        }
        for(int j = 1; j <= K; j++) {
            for(int k = 1; k <= A[i]; k++) {
                if(k <= j) {
                    int64_t x = (fact[j] * invf[k] % MOD) * invf[j - k] % MOD;
                    dp[j - k] += dp[j] * x % MOD;
                    dp[j - k] %= MOD;
                }
            }
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < K; i++) {
        int64_t x = (fact[K] * invf[i] % MOD) * invf[K - i] % MOD;
        dp[i] *= q_pow(x, MOD - 2);
        dp[i] %= MOD;

        ans += dp[i];
        ans %= MOD;
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
