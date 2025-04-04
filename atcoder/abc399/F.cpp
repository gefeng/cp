#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

// for power of k, common trick is to consider combinatorics
// try to make given equation to form (a + b) ^ k
// this gives chance to utilize binomial coefficient

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
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> fact(K + 1, 1);
    std::vector<int64_t> invf(K + 1, 1);
    for(int i = 1; i <= K; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    // dp[k][r] result of sub-arrays ending at r, power is k
    std::vector<std::vector<int64_t>> dp(K + 1, std::vector<int64_t>(N, 0));
    
    for(int k = 0; k <= K; k++) {
        dp[k][0] = q_pow(A[0], k);
    }

    int64_t ans = 0;
    for(int r = 1; r < N; r++) {
        for(int k = 0; k <= K; k++) {
            dp[k][r] = q_pow(A[r], k);
            for(int i = 0; i <= k; i++) {
                dp[k][r] += (((fact[k] * invf[i] % MOD) * invf[k - i] % MOD) * q_pow(A[r], i) % MOD) * dp[k - i][r - 1] % MOD;
                dp[k][r] %= MOD;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        ans += dp[K][i];
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
