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
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::vector<int64_t> psum(N + 1, 0);
    for(int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + B[i];
    }

    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(N + 1, INF));
    dp[0][0] = 0;
    dp[1][0] = 0;
    for(int i = 1; i <= N; i++) {
        dp[0][i] = psum[i - 1]; 
        for(int j = 1; j < i; j++) {
            if(A[i - 1] >= A[j - 1]) {
                dp[0][i] = std::min(dp[0][i], dp[0][j] + psum[i - 1] - psum[j]);
            }
            dp[1][i] = std::min(dp[1][i], dp[0][j] + psum[i] - psum[j]);
            dp[1][i] = std::min(dp[1][i], dp[1][j] + psum[i] - psum[j]);
        }
    }

    std::cout << std::min(dp[0][N], dp[1][N]) << '\n';
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
