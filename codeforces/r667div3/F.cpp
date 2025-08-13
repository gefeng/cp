#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::string S, T;
    std::cin >> S >> T;

    if(T[0] == T[1]) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            if(S[i] != T[0] && K) {
                S[i] = T[0];
                K -= 1;
            }
            if(S[i] == T[0]) {
                cnt += 1;
            }
        }

        std::cout << static_cast<int64_t>(cnt - 1) * cnt / 2 << '\n';
        return;
    }

    std::vector<std::vector<int64_t>> dp(N + 1, std::vector<int64_t>(K + 1, -1));
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        std::vector<std::vector<int64_t>> n_dp(dp);
        
        for(int j = 0; j <= i + 1; j++) {
            for(int k = 0; k <= std::min(K, i + 1); k++) {
                if(S[i] == T[0] && j && k < i + 1) {
                    n_dp[j][k] = std::max(n_dp[j][k], dp[j - 1][k]);
                }
                if(S[i] == T[1] && j < i + 1 && k < i + 1 && dp[j][k] != -1) {
                    n_dp[j][k] = std::max(n_dp[j][k], dp[j][k] + j);
                }

                if(j && k) {
                    n_dp[j][k] = std::max(n_dp[j][k], dp[j - 1][k - 1]);
                } 
                if(j < i + 1 && k && dp[j][k - 1] != -1) {
                    n_dp[j][k] = std::max(n_dp[j][k], dp[j][k - 1] + j);
                }
            }
        }

        dp = std::move(n_dp);
    }

    int64_t ans = 0;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
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
