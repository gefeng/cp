#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

constexpr int MAX = 30;
constexpr double INF = 1e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int64_t, int64_t>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto dist = [&](int i, int j) {
        return sqrt((A[j].first - A[i].first) * (A[j].first - A[i].first) + 
               (A[j].second - A[i].second) * (A[j].second - A[i].second));
    };

    int max_skip = std::min(N - 2, MAX);
    std::vector<std::vector<double>> dp(N, std::vector<double>(max_skip + 1, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j <= max_skip; j++) {
            for(int k = 0; k <= max_skip - j; k++) {
                if(i + k + 1 < N) {
                    dp[i + k + 1][j + k] = std::min(dp[i + k + 1][j + k], dp[i][j] + dist(i, i + k + 1));
                }
            }
        }
    }

    double ans = 1e18;
    for(int i = 0; i <= max_skip; i++) {
        ans = std::min(ans, dp[N - 1][i] + (i == 0 ? 0 : (1 << (i - 1))));
    }

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
