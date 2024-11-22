#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    if(K == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(N + 1, 0));
    
    for(int k = 2; k <= K; k++) {
        std::vector<std::vector<int64_t>> ndp(2, std::vector<int64_t>(N + 1, 0));
        
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j < 2; j++) {
                ndp[j][i] = (1 + dp[j ^ 1][N - i]) % MOD;
                ndp[j][i] += ndp[j][i - 1];
                ndp[j][i] %= MOD;
            }
        }

        std::swap(dp, ndp);
    }

    int64_t ans = (dp[0][N] + 1) % MOD;

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
