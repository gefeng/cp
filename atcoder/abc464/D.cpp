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

    std::string S;
    std::cin >> S;

    std::vector<int> A(N);
    std::vector<int> B(N - 1);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    for(int i = 0; i < N - 1; i++) {
        std::cin >> B[i];
    }

    std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(N + 1, -INF));
    dp[0][1] = 0;
    dp[1][1] = -A[0];

    for(int i = 2; i <= N; i++) {
        dp[0][i] = std::max(dp[0][i], dp[0][i - 1] + (S[i - 2] == 'R' && S[i - 1] == 'S' ? B[i - 2] : 0));
        dp[0][i] = std::max(dp[0][i], dp[1][i - 1] + (S[i - 2] == 'S' && S[i - 1] == 'S' ? B[i - 2] : 0));
        dp[1][i] = std::max(dp[1][i], dp[0][i - 1] + (S[i - 2] == 'R' && S[i - 1] == 'R' ? B[i - 2] - A[i - 1] : -A[i - 1]));
        dp[1][i] = std::max(dp[1][i], dp[1][i - 1] + (S[i - 2] == 'S' && S[i - 1] == 'R' ? B[i - 2] - A[i - 1] : -A[i - 1]));
    }

    std::cout << std::max(dp[0][N], dp[1][N]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
