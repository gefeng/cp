#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string A, B;
    std::cin >> A >> B;

    std::vector<std::vector<int>> dp(N, std::vector<int>(M, 0));
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i] == B[j]) {
                dp[i][j] = 2;
                if(i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 2);
                }
                if(i - 1 >= 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j] - 1);
                }
                if(j - 1 >= 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i][j - 1] - 1);
                }
            } else {
                if(i - 1 >= 0 && j - 1 >= 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] - 2);
                }
                if(i - 1 >= 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j] - 1);
                }
                if(j - 1 >= 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i][j - 1] - 1);
                }
            }
            ans = std::max(ans, dp[i][j]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
