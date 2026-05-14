#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

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
    int N;
    std::cin >> N;

    std::vector<int> A(N - 1);
    for(int i = 0; i < N - 1; i++) {
        std::cin >> A[i];
    }

    std::map<int, int64_t> dp;
    int64_t coef = 1;
    dp[N - 1] = 1;
    dp[N - 2] = 1;
    for(int i = N - 3; i >= 0; i--) {
        int64_t x = dp.find(i + A[i]) == dp.end() ? 0 : dp[i + A[i]];

        if(A[i] == A[i + 1]) {
            // for(int j = i + 1; j < N; j++) {
            //     ndp[j] += (N - 2 - i) * dp[j] % MOD;
            //     ndp[j] %= MOD;
            // }

            coef *= N - 2 - i;
            coef %= MOD;

            int64_t inv = q_pow(N - 2 - i, MOD - 2);
            dp[i] += x * inv % MOD;
            dp[i] %= MOD;
            dp[i + A[i]] += x * inv % MOD;
            dp[i + A[i]] %= MOD;
        } else {
            dp.clear();
            dp[i] = x;
            dp[i + A[i]] = x;
        }
    }

    int64_t ans = 0;
    for(auto [_, x] : dp) {
        ans += x;
        ans %= MOD;
    }
    ans *= coef;
    ans %= MOD;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
