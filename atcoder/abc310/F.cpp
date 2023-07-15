#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;
constexpr int MAX = (int)1e6;

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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> inv(MAX + 1, 1);
    for(int i = 2; i <= MAX; i++) {
        inv[i] = q_pow(i, MOD - 2); 
    }

    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(1 << 11, 0));
    dp[0][1] = 1;

    for(int i = 0; i < N; i++) {
        int v = A[i];
        for(int j = 1; j < (1 << 11); j++) {
            if(v > 10) {
                int d = v - 10;
                dp[i + 1][j] += (dp[i][j] * d % MOD) * inv[v] % MOD;
                dp[i + 1][j] %= MOD;
            } 

            for(int k = 1; k <= std::min(10, v); k++) {
                int nj = (j | (j << k)) & ((1 << 11) - 1);
                /*for(int s = 0; s <= 10; s++) {
                    if((j & (1 << s))) {
                        if(s + k <= 10) {
                            nj |= (1 << (s + k)); 
                        }
                    }
                }*/

                dp[i + 1][nj] += dp[i][j] * inv[v] % MOD;
                dp[i + 1][nj] %= MOD;
            }
        } 
    }

    int64_t ans = 0;
    for(int i = 0; i < (1 << 11); i++) {
        if(i & (1 << 10)) {
            ans += dp[N][i];
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
