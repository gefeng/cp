#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

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

    std::vector<std::array<int64_t, 4>> A(N);
    int64_t tot = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            std::cin >> A[i][j];
        }
        int64_t P, Q;
        std::cin >> P >> Q;
        A[i][2] = P * q_pow(Q, MOD - 2) % MOD;
        A[i][3] = q_pow((1 - A[i][2] + MOD) % MOD, MOD - 2);
        tot *= (1 - A[i][2] + MOD) % MOD;
        tot %= MOD;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x[0] < y[0];
            });

    if(A[0][0] != 1) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int64_t> dp(M + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < N; i++) {
        int l = A[i][0];
        int r = A[i][1];
        int64_t p = A[i][2];
        int64_t q = A[i][3];
        if(dp[l - 1] != 0) {
            dp[r] += dp[l - 1] * (p * q % MOD) % MOD;
            dp[r] %= MOD;
        }
    }

    int64_t ans = tot * dp[M] % MOD;
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
