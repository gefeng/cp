#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <functional>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S, T;
    std::cin >> S >> T;

    std::vector<std::vector<int>> dp(M + 1, std::vector<int>(N + 1, INF));
    for(int i = 0; i <= N; i++) {
        dp[0][i] = i == 0 ? 0 : 1;
    }    

    for(int i = 1; i <= M; i++) {
        int min_v = INF;
        for(int j = 1; j <= N; j++) {
            if(S[j - 1] == T[i - 1]) {
                if(dp[i - 1][j - 1] != INF) {
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
            
            if(min_v != INF) {
                dp[i][j] = std::min(dp[i][j], min_v + 1);
            }
            min_v = std::min(min_v, dp[i][j]);
        }
    }

    int ans = INF;
    for(int i = M; i <= N; i++) {
        if(dp[M][i] != INF) {
            ans = std::min(ans, dp[M][i] + (N - i == 0 ? 0 : 1));
        } 
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
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
