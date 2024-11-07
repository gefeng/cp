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
    int N, M;
    std::cin >> N >> M;

    int64_t inv2 = q_pow(2, MOD - 2);
    std::vector<std::vector<int64_t>> dp(M + 1, std::vector<int64_t>(N + 1, 0));
    dp[0][0] = 1;
    dp[1][1] = inv2;
    for(int i = 1; i <= M; i++) {
        dp[i][0] = dp[i - 1][0] * inv2 % MOD;
    }

    for(int i = 2; i <= M; i++) {
        for(int j = 1; j <= N; j++) {
            dp[i][j] += dp[i - 1][j] * (j == N ? 1 : inv2) % MOD;
            dp[i][j] %= MOD;

            dp[i][j] += dp[i - 1][j - 1] * inv2 % MOD;
            dp[i][j] %= MOD;
        }
    }
    
    for(int i = 1; i <= M; i++) {
        std::cout << dp[i][N] << " \n"[i == M];
    }
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
