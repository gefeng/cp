#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

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

    int n = N;
    for(int i = 0; i < K; i++) {
        int R, C;
        std::cin >> R >> C;
        if(R == C) {
            n -= 1;
        } else {
            n -= 2;
        }
    }

    std::vector<int64_t> fact(n + 1, 1);
    std::vector<int64_t> invf(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    std::vector<int64_t> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 2; i <= n; i += 2) {
        dp[i] = (dp[i - 2] * i % MOD) * (i - 1) % MOD;
        dp[i] *= q_pow(i / 2, MOD - 2);
        dp[i] %= MOD;
    }

    int64_t ans = 0;
    for(int i = 0; i <= n; i++) {
        if((n - i) % 2 == 0) {
            int64_t x = (fact[n] * invf[i] % MOD) * invf[n - i] % MOD;
            ans += x * dp[n - i] % MOD;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
