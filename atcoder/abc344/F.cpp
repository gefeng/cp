#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = (int64_t)2e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> A(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> B(N, std::vector<int>(N - 1, 0));
    std::vector<std::vector<int>> C(N - 1, std::vector<int>(N, 0));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> A[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - 1; j++) {
            std::cin >> B[i][j];
        }
    }

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N; j++) {
            std::cin >> C[i][j];
        }
    }

    std::vector<std::vector<std::vector<std::vector<std::pair<int64_t, int64_t>>>>> dp(N, 
            std::vector<std::vector<std::vector<std::pair<int64_t, int64_t>>>>(N, 
                std::vector<std::vector<std::pair<int64_t, int64_t>>>(N, 
                    std::vector<std::pair<int64_t, int64_t>>(N, {INF, INF}))));
    
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(r == 0 && c == 0) {
                dp[r][c][r][c] = {0, 0};
            } else {
                for(int x = 0; x <= r; x++) {
                    for(int y = 0; y <= c; y++) {
                        if(x < r && dp[r - 1][c][x][y].first != INF) {
                            auto [pre_act, pre_bal] = dp[r - 1][c][x][y];
                            int64_t cnt = pre_bal >= C[r - 1][c] ? 0 : (C[r - 1][c] - pre_bal + A[x][y] - 1) / A[x][y];
                            int64_t act = pre_act + cnt + 1;
                            int64_t bal = pre_bal + A[x][y] * cnt - C[r - 1][c];
                            
                            if(A[r][c] > A[x][y]) {
                                if(act < dp[r][c][r][c].first || (act == dp[r][c][r][c].first && bal > dp[r][c][r][c].second)) {
                                    dp[r][c][r][c] = {act, bal};
                                }
                            } else {
                                if(act < dp[r][c][x][y].first || (act == dp[r][c][x][y].first && bal > dp[r][c][x][y].second)) {
                                    dp[r][c][x][y] = {act, bal};
                                }
                            }
                        }

                        if(y < c && dp[r][c - 1][x][y].first != INF) {
                            auto [pre_act, pre_bal] = dp[r][c - 1][x][y];
                            int64_t cnt = pre_bal >= B[r][c - 1] ? 0 : (B[r][c - 1] - pre_bal + A[x][y] - 1) / A[x][y]; 

                            int64_t act = pre_act + cnt + 1;
                            int64_t bal = pre_bal + A[x][y] * cnt - B[r][c - 1];
                            if(A[r][c] > A[x][y]) {
                                if(act < dp[r][c][r][c].first || (act == dp[r][c][r][c].first && bal > dp[r][c][r][c].second)) {
                                    dp[r][c][r][c] = {act, bal};
                                }
                            } else {
                                if(act < dp[r][c][x][y].first || (act == dp[r][c][x][y].first && bal > dp[r][c][x][y].second)) {
                                    dp[r][c][x][y] = {act, bal};
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int64_t ans = INF;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans = std::min(ans, dp[N - 1][N - 1][i][j].first);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
