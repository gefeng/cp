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

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(4, INF));
    dp[0][0] = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 4; j++) {
            dp[i][0] = std::min(dp[i][0], dp[i - 1][j] + (A[i - 1] == 0 ? 0 : 1));
        }
        if(A[i - 1] <= 4) {
            for(int j = 0; j < 4; j++) {
                if(dp[i - 1][j] == INF) {
                    continue; 
                }
                
                for(int k = 0; k < 4; k++) {
                    int mask = k | j;
                    if(!(mask & 1)) {
                        continue;
                    }
                    
                    if(A[i - 1] > 2 && !(mask & 2)) {
                        continue;
                    }

                    dp[i][k] = std::min(dp[i][k], dp[i - 1][j] + __builtin_popcount(k));
                }
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < 4; i++) {
        ans = std::min(ans, dp[N][i]);
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
