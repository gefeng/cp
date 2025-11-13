#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> dp(3, std::vector<int>(N, INF));
    if(A[0] == 0) {
        for(int i = 0; i < 3; i++) {
            dp[i][0] = i;
        }
    } else {
        for(int i = 1; i < 3; i++) {
            dp[i][0] = i - 1;
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                if(k < A[i] || dp[j][i - 1] == INF || k == j) {
                    continue;
                }

                dp[k][i] = std::min(dp[k][i], dp[j][i - 1] + k - A[i]);
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < 3; i++) {
        ans = std::min(ans, dp[i][N - 1]);
    }

    std::cout << ans << '\n';
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
