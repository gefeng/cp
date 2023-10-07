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
    int N, X;
    std::cin >> N >> X;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int64_t> inv(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        inv[i] = q_pow(i, MOD - 2);
    }

    std::vector<int64_t> dp(X + 1, 0); // probability that song ends at time i
    dp[0] = 1;
    
    for(int i = 0; i <= X; i++) {
        for(int j = 0; j < N; j++) {
            if(i - A[j] >= 0) {
                dp[i] += dp[i - A[j]] * inv[N] % MOD;
                dp[i] %= MOD;
            }
        }
    }

    int64_t ans = 0;
    for(int i = std::max(0, X - A[0] + 1); i <= X; i++) {
        ans += dp[i] * inv[N] % MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
