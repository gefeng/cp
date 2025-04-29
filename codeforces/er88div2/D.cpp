#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = int(2e9);

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = -INF;
    for(int x = -30; x <= 30; x++) {
        std::vector<std::vector<int>> dp(2, std::vector<int>(N, -INF));
        if(A[0] <= x) {
            dp[0][0] = A[0];
            if(x == A[0]) {
                dp[1][0] = 0;
            }
            ans = std::max(ans, dp[1][0]);
        }

        for(int i = 1; i < N; i++) {
            if(A[i] > x) {
                continue;
            }
            // merge to previous
            if(dp[0][i - 1] != -INF) {
                dp[0][i] = std::max(dp[0][i], dp[0][i - 1] + A[i]);
                if(x == A[i]) {
                    dp[1][i] = std::max(dp[1][i], dp[0][i - 1]);
                }
            }
            if(dp[1][i - 1] != -INF) {
                dp[1][i] = std::max(dp[1][i], dp[1][i - 1] + A[i]);
            } 

            // start a new one
            dp[0][i] = std::max(dp[0][i], A[i]);
            if(x == A[i]) {
                dp[1][i] = std::max(dp[1][i], 0);
            }

            ans = std::max(ans, dp[1][i]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
