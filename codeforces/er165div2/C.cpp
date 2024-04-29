#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = int64_t(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int64_t>> dp(K + 1, std::vector<int64_t>(N + 1, INF));
    dp[0][0] = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= std::min(K, i - 1); j++) {
            dp[j][i] = std::min(dp[j][i], dp[j][i - 1] + A[i - 1]);

            for(int k = 1; k <= j; k++) {
                dp[j][i] = std::min(dp[j][i], dp[j - k][i - k - 1] + int64_t(k + 1) * A[i - 1]);
            }

            for(int k = 1; k + j <= K && i + k <= N; k++) {
                dp[k + j][i + k] = std::min(dp[k + j][i + k], dp[j][i] + int64_t(k) * A[i - 1]);
            }            
        }
    }

    int64_t ans = INF;
    for(int i = 0; i <= K; i++) {
        ans = std::min(ans, dp[i][N]);
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
