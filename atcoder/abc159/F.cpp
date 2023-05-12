#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = 998244353LL;

void run_case() {
    int N, S;
    std::cin >> N >> S;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<LL>> dp(N + 1, std::vector<LL>(S + 1, 0LL));
    std::vector<std::vector<LL>> ds(N + 2, std::vector<LL>(S + 1, 0LL));

    dp[0][0] = 1LL;
    for(int i = 1; i <= N + 1; i++) {
        ds[i][0] = 1LL;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= S; j++) {
            if(j - A[i - 1] >= 0) {
                dp[i][j] += (ds[i][j - A[i - 1]] - ds[0][j - A[i - 1]] + MOD) % MOD;
                dp[i][j] %= MOD;
            }

            ds[i + 1][j] += dp[i][j];
            ds[i + 1][j] %= MOD;
        }

        for(int j = 0; j <= S; j++) {
            ds[i + 1][j] += ds[i][j];
            ds[i + 1][j] %= MOD;
        } 
    }

    LL ans = 0LL;
    for(int i = 1; i <= N; i++) {
        ans += dp[i][S] * (N - i + 1) % MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
