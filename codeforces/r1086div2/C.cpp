#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::vector<double> dp(N, 0);
    dp[N - 1] = A[N - 1].first;
    
    for(int i = N - 2; i >= 0; i--) {
        dp[i] = dp[i + 1];
        double coe = (100.0 - A[i].second) / 100.0;
        dp[i] = std::max(dp[i + 1], dp[i + 1] * coe + A[i].first);
    }

    std::cout << std::setprecision(20) << dp[0] << '\n';
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
