#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = int64_t(1e15) + 20000;
constexpr int64_t INF = int64_t(4e18);

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    int64_t ans = INF;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(A[i][j] - i - j <= A[0][0]) {
                std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(M, INF));
                int64_t d = A[0][0] - (A[i][j] - i - j);
                dp[0][0] = d;
                for(int i = 0; i < N; i++) {
                    for(int j = 0; j < M; j++) {
                        if(i == 0 && j == 0) {
                            continue;
                        }
                        if(i && dp[i - 1][j] != INF) {
                            int64_t x = A[0][0] - d + i + j;     
                            if(A[i][j] >= x) {
                                dp[i][j] = std::min(dp[i][j], dp[i - 1][j] + A[i][j] - x);
                            }
                        }
                        if(j && dp[i][j - 1] != INF) {
                            int64_t x = A[0][0] - d + i + j;     
                            if(A[i][j] >= x) {
                                dp[i][j] = std::min(dp[i][j], dp[i][j - 1] + A[i][j] - x);
                            }
                        }
                    }
                }

                ans = std::min(ans, dp[N - 1][M - 1]);
            }
        }
    }

    std::cout << int64_t(ans) << '\n';
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
