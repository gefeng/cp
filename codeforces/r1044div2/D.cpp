#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <ranges>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    
    std::vector<int> pre(N, -1);
    for(int i = 1; i < N; i++) {
        pre[i] = A[i - 1] == 1 ? pre[i - 1] : i - 1;
    }

    std::vector<int64_t> dp(N + 1, INF);
    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + A[i - 1];
        
        if(i > 1) {
            dp[i] = std::min(dp[i], dp[i - 1] + A[i - 1] - 1);
        }
        if(i > 2) {
            dp[i] = std::min(dp[i], dp[i - 2] + A[i - 2] + std::max(0, A[i - 1] - i + 1));
        }
    }
    
    std::cout << dp[N] << '\n';
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
