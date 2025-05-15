#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

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
    std::vector<int> A;
    int sum = 0;
    for(int i = 0; i < 26; i++) {
        int X;
        std::cin >> X;
        if(X) {
            A.push_back(X);
            sum += X;
        }
    }

    int N = A.size();
    int eve = (sum + 1) / 2;
    int odd = sum / 2;

    std::vector<int64_t> fact(sum + 1, 1);
    std::vector<int64_t> invf(sum + 1, 1);
    
    for(int i = 1; i <= sum; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(eve + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= N; i++) {
        int f = A[i - 1];
        for(int j = 0; j <= eve; j++) {
            dp[i][j] += dp[i - 1][j] * invf[f] % MOD;
            dp[i][j] %= MOD;
            if(j - f >= 0) {
                int rem = eve - (j - f);
                int64_t x = (fact[rem] * invf[f] % MOD * invf[rem - f] % MOD);
                dp[i][j] += dp[i - 1][j - f] * x % MOD;
                dp[i][j] %= MOD;
            }
        }
    }

    int64_t ans = dp[N][eve] * fact[odd] % MOD;
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
