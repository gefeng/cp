#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)1e18;

void run_case() {
    int M, X;
    std::cin >> M >> X;

    std::vector<int> A(M);
    std::vector<int> B(M);
    int n = 0;
    for(int i = 0; i < M; i++) {
        std::cin >> A[i] >> B[i];
        n += B[i];
    }

    std::vector<std::vector<int64_t>> dp(M + 1, std::vector<int64_t>(n + 1, INF));
    dp[0][0] = 0;
    
    for(int i = 1; i <= M; i++) {
        int64_t bal = (int64_t)(i - 1) * X; 
        for(int j = 0; j <= n; j++) {
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j]); 
            
            if(j - B[i - 1] >= 0 && dp[i - 1][j - B[i - 1]] != INF && bal - dp[i - 1][j - B[i - 1]] >= A[i - 1]) {
                dp[i][j] = std::min(dp[i][j], dp[i - 1][j - B[i - 1]] + A[i - 1]);
            }
        }
    }

    int ans = 0;
    for(int i = n; i >= 0; i--) {
        if(dp[M][i] != INF) {
            ans = i;
            break;
        } 
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
