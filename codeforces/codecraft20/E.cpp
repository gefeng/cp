#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, P, K;
    std::cin >> N >> P >> K;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::vector<std::vector<int>> B(N, std::vector<int>(P, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < P; j++) {
            std::cin >> B[i][j];
        }
    }

    std::ranges::sort(A, std::greater<std::pair<int, int>>());

    int64_t ans = 0;
    std::vector<int64_t> dp(1 << P, -1);
    dp[0] = 0;
    
    for(int i = 0; i < N; i++) {
        auto [s, idx] = A[i];
        std::vector<int64_t> n_dp(1 << P, -1);

        for(int mask = 0; mask < (1 << P); mask++) {
            if(dp[mask] == -1) {
                continue;
            }

            int cnt = __builtin_popcount(mask);
            if(i - cnt < K) {
                n_dp[mask] = std::max(n_dp[mask], dp[mask] + s);
            } else {
                n_dp[mask] = std::max(n_dp[mask], dp[mask]);
            }

            for(int j = 0; j < P; j++) {
                if(mask & (1 << j)) {
                    continue;
                }
                n_dp[mask | (1 << j)] = std::max(n_dp[mask | (1 << j)], dp[mask] + B[idx][j]);
            }
        }

        dp = std::move(n_dp);
        
        if(dp[(1 << P) - 1] != -1 && i + 1 - P >= K) {
            ans = std::max(ans, dp[(1 << P) - 1]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
