#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int BASE = int(1e4);
constexpr int MOD = int(1e9) + 7;

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

int64_t inv = q_pow(BASE, MOD - 2);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int64_t> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> P(N);
    for(int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    std::vector<int64_t> p2(30, 1);
    for(int i = 1; i < 30; i++) {
        p2[i] = p2[i - 1] * 2 % MOD;
    }

    int64_t ans = 0;
    for(int a = 0; a < 10; a++) {
        for(int b = 0; b < 10; b++) {
            std::array<std::array<int64_t, 2>, 2> dp = {};
            dp[0][0] = 1;
            for(int i = 0; i < N; i++) {
                std::array<std::array<int64_t, 2>, 2> ndp = {};
                for(int j = 0; j < 2; j++) {
                    for(int k = 0; k < 2; k++) {
                        ndp[j][k] += dp[j][k] * ((BASE - P[i]) * inv % MOD) % MOD;
                        ndp[j][k] %= MOD;
                        ndp[j][k] += dp[(A[i] >> a & 1) ^ j][(A[i] >> b & 1) ^ k] * (P[i] * inv % MOD) % MOD;
                        ndp[j][k] %= MOD;
                    }
                }
                std::swap(dp, ndp);
            }

            ans += dp[1][1] * p2[a + b] % MOD;
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
