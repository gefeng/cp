#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)2e9;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::vector<int>>> dp(N + 1, std::vector<std::vector<int>>(N + 1, std::vector<int>(N + 1, INF)));
    dp[0][0][0] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            for(int k = j; k <= N; k++) {
                if(dp[i][j][k] != INF) {
                    int l = std::max(0, i - A[i] + 1);
                    int r = std::min(N - 1, i + A[i] - 1);
                 
                    // not use
                    dp[i + 1][j][k] = std::min(dp[i + 1][j][k], dp[i][j][k]);
                    
                    // paint left
                    if(j != N && l <= j) {
                        if(j == k) {
                            dp[i + 1][i + 1][i + 1] = std::min(dp[i + 1][i + 1][i + 1], dp[i][j][k] + 1);
                        } else {
                            dp[i + 1][k][k] = std::min(dp[i + 1][k][k], dp[i][j][k] + 1);
                        }
                    }

                    // paint right
                    if(k != N && r >= k) {
                        if(j == k) {
                            if(k >= i) {
                                dp[i + 1][r + 1][r + 1] = std::min(dp[i + 1][r + 1][r + 1], dp[i][j][k] + 1);
                            } else {
                                dp[i + 1][j][r + 1] = std::min(dp[i + 1][j][r + 1], dp[i][j][k] + 1);
                            }
                        } else {
                            if(k >= i) {
                                dp[i + 1][j][r + 1] = std::min(dp[i + 1][j][r + 1], dp[i][j][k] + 1);
                            }
                        }
                    }
                }
            }
        }
    }

    std::cout << dp[N][N][N] << '\n'; 
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
