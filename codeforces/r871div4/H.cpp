#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<LL>> dp(N + 1, std::vector<LL>(1 << 6, 0LL));
    for(int i = 0; i < N; i++) {
        dp[i + 1][A[i]] = 1LL;
        for(int j = 0; j < 64; j++) {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;

            dp[i + 1][j & A[i]] += dp[i][j];
            dp[i + 1][j & A[i]] %= MOD;
        }
    } 

    LL ans = 0LL;
    for(int i = 0; i < 64; i++) {
        if(__builtin_popcount(i) == K) {
            ans += dp[N][i];
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
