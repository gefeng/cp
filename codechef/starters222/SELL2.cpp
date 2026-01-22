#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));
    for(int i = 1; i <= N; i++) {
        int profit = A[i - 1];
        
        for(int j = 0; j <= i - 1; j++) {
            int k = i - j;
            dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
            dp[i][j + 1] = std::max(dp[i][j + 1], dp[i - 1][j] + profit);
            if(k > 1) {
                dp[i][j + 2] = std::max(dp[i][j + 2], dp[i - 1][j] + profit * 2);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= N; i++) {
        ans = std::max(ans, dp[N][i]);
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
