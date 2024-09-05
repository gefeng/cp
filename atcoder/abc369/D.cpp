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

    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(2, -1));
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++) {
        if(dp[i - 1][0] != -1) {
            int64_t beat = dp[i - 1][0] + A[i - 1];
            int64_t skip = dp[i - 1][0];
            dp[i][1] = std::max(dp[i][1], beat);
            dp[i][0] = std::max(dp[i][0], skip);
        } 
        if(dp[i - 1][1] != -1) {
            int64_t beat = dp[i - 1][1] + A[i - 1] + A[i - 1];
            int64_t skip = dp[i - 1][1];
            dp[i][0] = std::max(dp[i][0], beat);
            dp[i][1] = std::max(dp[i][1], skip);
        }
    }

    std::cout << std::max(dp[N][0], dp[N][1]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
