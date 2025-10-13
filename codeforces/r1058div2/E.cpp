#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int INF = static_cast<int>(2e9);

template<class T>
std::vector<std::vector<T>> transpose(const std::vector<std::vector<T>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    std::vector<std::vector<T>> t_mat(m, std::vector<T>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            t_mat[j][i] = mat[i][j];
        }
    }
    return t_mat;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<char>> G(N, std::vector<char>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> G[i][j];
        }
    }

    bool transposed = false;
    if(N > M) {
        G = transpose(G);
        std::swap(N, M);
        transposed = true;
    }

    std::vector<std::vector<int>> ans(N, std::vector<int>(M, INF));
    // more time and space optimized version but also more tricky to implement
    for(int r1 = 0; r1 < N; r1++) {
        for(int r2 = N - 1; r2 > r1; r2--) {
            std::vector<int> border;
            for(int c = 0; c < M; c++) {
                if(G[r1][c] == '1' && G[r2][c] == '1') {
                    border.push_back(c);
                }
            }
            int size = border.size();
            std::vector<int> dp(M, INF);
            for(int i = 0; i < size - 1; i++) {
                int l = border[i];
                int r = border[i + 1];
                for(int p = l; p <= r; p++) {
                    dp[p] = std::min(dp[p], (r - l + 1) * (r2 - r1 + 1));
                    ans[r2][p] = std::min(ans[r2][p], dp[p]);
                }
            }

            for(int c = 0; c < M; c++) {
                if(r2 + 1 < N) {
                    ans[r2][c] = std::min(ans[r2][c], ans[r2 + 1][c]);
                }
                ans[r1][c] = std::min(ans[r1][c], dp[c]);
            }
        }
    }
    
    // for(int c = M - 1; c >= 0; c--) {
    //     for(int r1 = 0; r1 < N - 1; r1++) {
    //         for(int r2 = r1 + 1; r2 < N; r2++) {
    //             if(border[r1][r2].empty() || border[r1][r2].back() < c) {
    //                 continue;
    //             }
    //
    //             int size = border[r1][r2].size();
    //             if(size > 1) {
    //                 dp[r1][r2] = std::min(dp[r1][r2], (r2 - r1 + 1) * (border[r1][r2].back() - border[r1][r2][size - 2] + 1));
    //                 
    //                 if(border[r1][r2][size - 2] == c) {
    //                     border[r1][r2].pop_back();
    //                     
    //                     if(size > 2) {
    //                         dp[r1][r2] = std::min(dp[r1][r2], (r2 - r1 + 1) * (border[r1][r2].back() - border[r1][r2][size - 3] + 1));
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //
    //     for(int len = N; len > 0; len--) {
    //         for(int r1 = 0; r1 <= N - len; r1++) {
    //             int r2 = r1 + len - 1; 
    //             dp[r1][r2] = std::min(dp[r1][r2], r1 - 1 >= 0 ? dp[r1 - 1][r2] : INF);
    //             dp[r1][r2] = std::min(dp[r1][r2], r2 + 1 < N ? dp[r1][r2 + 1] : INF);
    //             if(r1 == r2) {
    //                 ans[r1][c] = dp[r1][r2] == INF ? 0 : dp[r1][r2];
    //             }
    //         }
    //     }
    // }

    if(transposed) {
        ans = transpose(ans);
        std::swap(N, M);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << (ans[i][j] == INF ? 0 : ans[i][j]) << " \n"[j == M - 1];
        }
    }
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
