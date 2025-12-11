#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, K;
    std::cin >> N >> K;

    K %= 2;
    
    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(N + 1, -INF));
    dp[0][0] = 0;
    
    int64_t max_s1 = -INF;
    int64_t max_s2 = -INF;
    for(int i = 1; i <= N; i++) {
        int64_t x = std::max(A[i - 1] + B[i - 1], A[i - 1] - B[i - 1]);
        dp[0][i] = std::max(A[i - 1], dp[0][i - 1] + A[i - 1]);
        dp[1][i] = std::max(x, dp[0][i - 1] + x);

        if(dp[1][i - 1] != -INF) {
            dp[1][i] = std::max(dp[1][i], std::max(dp[1][i - 1] + A[i - 1], A[i - 1]));
        }
        max_s1 = std::max(max_s1, dp[0][i]);
        max_s2 = std::max(max_s2, dp[1][i]);
    }

    if(K == 0) {
        std::cout << max_s1 << '\n';
    } else {
        std::cout << max_s2 << '\n';
    }
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
