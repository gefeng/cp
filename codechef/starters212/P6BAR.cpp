#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(1e9) + 7;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(N == 1) {
        std::cout << (K == 1 ? 1 : 0) << '\n';
        return;
    }

    if(K < 3) {
        std::cout << 0 << '\n';
        return;
    }
    
    std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(K + 1, 0));
    dp[0][1] = 1;
    dp[1][3] = 2;

    for(int i = 2; i < N; i++) {
        for(int j = 0; j <= K; j++) {
            dp[i][j] += dp[i - 1][j] * (i - 1) % MOD;
            dp[i][j] %= MOD;
            if(j + 1 <= K) {
                dp[i][j + 1] += dp[i - 1][j] * 2 % MOD;
                dp[i][j + 1] %= MOD;
            }
        }
    }

    std::cout << dp[N - 1][K] << '\n';
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
