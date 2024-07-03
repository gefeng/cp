#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;
constexpr int MAX = 1000;

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::vector<int64_t>>> dp(N + 1, std::vector<std::vector<int64_t>>(MAX * 2 + 1, std::vector<int64_t>(2, 0)));
    dp[0][MAX][0] = 1;
    
    for(int i = 0; i < N; i++) {
        for(int j = -MAX; j <= MAX; j++) {
            if(j == 0) {
                continue;
            }

            for(int k = 0; k < 2; k++) {
                dp[i + 1][j + MAX][k] += dp[i][j + MAX][k];
                dp[i + 1][j + MAX][k] %= MOD;

                int nj = j + A[i];
                if(nj >= -MAX && nj <= MAX) {
                    dp[i + 1][nj + MAX][0] += dp[i][j + MAX][k];
                    dp[i + 1][nj + MAX][0] %= MOD;
                }
            }
        }

        dp[i + 1][MAX][0] += dp[i][MAX][0];
        dp[i + 1][MAX][0] %= MOD;
        if(A[i] != 0) {
            dp[i + 1][A[i] + MAX][1] = dp[i][MAX][0]; 
            dp[i + 1][A[i] + MAX][1] %= MOD;
        } 
    }

    int64_t ans = 0;
    for(int i = -MAX; i <= MAX; i++) {
        ans += dp[N][i + MAX][0];
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
