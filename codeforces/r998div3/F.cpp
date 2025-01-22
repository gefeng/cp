#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);
constexpr int MAX = 16;

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
    int K, N;
    std::cin >> K >> N;

    std::vector<std::vector<int64_t>> dp(MAX + 1, std::vector<int64_t>(K + 1, 0));
    for(int k = 2; k <= K; k++) {
        dp[1][k] = 1;
    }

    for(int i = 2; i <= MAX; i++) {
        for(int k = 2; k <= K; k++) {
            for(int j = k + k; j <= K; j += k) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    for(int k = 1; k <= K; k++) {
        int64_t ans = 0;


        if(k == 1) {
            std::cout << N << " \n"[k == K];
            continue;
        }

        std::vector<int> p_factors;
        int x = k;
        for(int f = 2; f * f <= x; f++) {
            while(x % f == 0) {
                p_factors.push_back(f);
                x /= f;
            }
        }
        if(x > 1) {
            p_factors.push_back(x);
        }

        int n = p_factors.size();
        // dp[1][k] = 1;
        // for(int j = 2; j <= n; j++) {
        //     int pre = -1;
        //     for(int p : p_factors) {
        //         if(p != pre) {
        //             dp[j][k] += dp[j - 1][k / p];
        //             dp[j][k] %= MOD;
        //             pre = p;
        //         }
        //     }
        // }

        // if(k == 8) {
        //     for(int i = 0; i <= n; i++) {
        //         std::cout << dp[i][k] << " \n"[i == n];
        //     }
        // }

        for(int len = 1; len <= std::min(N, n); len++) {
            int64_t a = 1;
            int64_t b = 1;
            for(int64_t i = N + 1; i >= N - len + 1; i--) {
                a *= i;
                a %= MOD; 
            }

            for(int64_t i = 1; i <= len + 1; i++) {
                b *= i;
                b %= MOD;
            }

            ans += (a * q_pow(b, MOD - 2) % MOD) * dp[len][k] % MOD;
            ans %= MOD;
        }

        std::cout << ans << " \n"[k == K];
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
