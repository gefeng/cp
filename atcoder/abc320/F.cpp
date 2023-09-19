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
    int N, H;
    std::cin >> N >> H;
    
    std::vector<int> A(N + 1, 0);
    std::vector<std::pair<int, int>> B(N + 1, {0, 0});
    for(int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    for(int i = 1; i < N; i++) {
        std::cin >> B[i].first >> B[i].second;
    }

    std::vector<std::vector<std::vector<int64_t>>> dp(N + 1, std::vector<std::vector<int64_t>>(H + 1, std::vector<int64_t>(H + 1, INF)));
    for(int i = 0; i <= H; i++) {
        dp[0][H][i] = 0;
    }

    for(int i = 0; i < N; i++) {
        int d = A[i + 1] - A[i];
        int f = B[i].second;
        int p = B[i].first; 
        for(int j = 0; j <= H; j++) {
            for(int k = 0; k <= H; k++) {
                // not fill
                if(j - d >= 0 && k + d <= H) {
                    dp[i + 1][j - d][k + d] = std::min(dp[i + 1][j - d][k + d], dp[i][j][k]);
                }
                
                // fill when moving forward
                int nj = std::min(H, j + f);
                if(nj - d >= 0 && k + d <= H && dp[i][j][k] != INF) {
                    dp[i + 1][nj - d][k + d] = std::min(dp[i + 1][nj - d][k + d], dp[i][j][k] + p);
                }

                // fill when moving backward
                if(k == H) {
                    // x + f >= H -> x >= H - f and x <= H
                    if(j - d >= 0 && dp[i][j][k] != INF) {
                        for(int x = std::max(0, H - f); x <= H; x++) {
                            if(x + d <= H) {
                                dp[i + 1][j - d][x + d] = std::min(dp[i + 1][j - d][x + d], dp[i][j][k] + p);
                            }
                        } 
                    }
                } else {
                    if(j - d >= 0 && k - f >= 0 && k - f + d <= H && dp[i][j][k] != INF) {
                        dp[i + 1][j - d][k - f + d] = std::min(dp[i + 1][j - d][k - f + d], dp[i][j][k] + p);
                    }
                }
            }
        }
    }

    int64_t ans = INF;
    for(int i = 0; i <= H; i++) {
        ans = std::min(ans, dp[N][i][i]);
    }

    std::cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
