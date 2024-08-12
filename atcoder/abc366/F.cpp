#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                return b.second * (a.first - 1) < a.second * (b.first - 1);
            });

    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(K + 1, 0));
    for(int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= N; i++) {
        auto [a, b] = A[i - 1];
        for(int j = 1; j <= K; j++) {
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
            
            if(dp[i - 1][j - 1] != 0) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] * a + b);
            }
        } 
    }

    std::cout << dp[N][K] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
