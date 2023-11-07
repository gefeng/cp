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
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int64_t rev_n = q_pow(N, MOD - 2);

    std::vector<int64_t> dp(N + 1, 0);
    dp[0] = 1;
    int64_t sum = 1;
    for(int i = 1; i <= N; i++) {
        dp[i] = sum * rev_n % MOD;
        sum += dp[i];
        sum %= MOD;
    }

    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        ans += dp[i + 1] * A[i] % MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
