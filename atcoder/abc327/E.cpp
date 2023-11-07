#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

constexpr double INF = 1e15;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<double>> dp(N + 1, std::vector<double>(N + 1, -INF));
    for(int i = 0; i <= N; i++) {
        dp[i][0] = 0;
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] * 0.9 + A[i - 1]);
        }
    }

    double ans = -INF;
    for(int i = 1; i <= N; i++) {
        double sum = 1.0;
        double coe = 1.0;
        for(int j = 1; j <= i; j++) {
            ans = std::max(ans, dp[i][j] / sum - 1200.0 / std::sqrt(j));
            coe *= 0.9;
            sum += coe;
        }
    }

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
