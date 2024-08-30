#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

constexpr int MAX = int(2e6);

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> G[i][j];
        }
    }
    
    std::vector<int> rows(N);
    std::iota(rows.begin(), rows.end(), 0);

    std::sort(rows.begin(), rows.end(), [&](int r1, int r2) {
                for(int c = 0; c < M; c++) {
                    if(G[r1][c] == G[r2][c]) {
                        continue;
                    }
                    
                    return G[r1][c] < G[r2][c];
                } return r1 < r2;
            });

    std::vector<std::vector<int>> dp1(N, std::vector<int>(M, 0));
    std::vector<std::vector<int>> dp2(N, std::vector<int>(M, MAX));
    std::vector<std::vector<int>> dp3(N, std::vector<int>(M, MAX));
    std::vector<std::vector<int>> dp4(N, std::vector<int>(M, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            dp1[i][j] = G[rows[i]][j];
            if(i) {
                dp1[i][j] = std::max(dp1[i][j], dp1[i - 1][j]);
            }
            if(j) {
                dp1[i][j] = std::max(dp1[i][j], dp1[i][j - 1]);
            }
        } 
    }
    
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j < M; j++) {
            dp2[i][j] = G[rows[i]][j];
            if(i + 1 < N) {
                dp2[i][j] = std::min(dp2[i][j], dp2[i + 1][j]);
            }
            if(j) {
                dp2[i][j] = std::min(dp2[i][j], dp2[i][j - 1]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = M - 1; j >= 0; j--) {
            dp3[i][j] = G[rows[i]][j];
            if(i) {
                dp3[i][j] = std::min(dp3[i][j], dp3[i - 1][j]);
            }
            if(j + 1 < M) {
                dp3[i][j] = std::min(dp3[i][j], dp3[i][j + 1]);
            }
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        for(int j = M - 1; j >= 0; j--) {
            dp4[i][j] = G[rows[i]][j];
            if(i + 1 < N) {
                dp4[i][j] = std::max(dp4[i][j], dp4[i + 1][j]);
            }
            if(j + 1 < M) {
                dp4[i][j] = std::max(dp4[i][j], dp4[i][j + 1]);
            }
        } 
    }


    for(int r = 0; r < N - 1; r++) {
        for(int c = 0; c < M - 1; c++) {
            if(dp1[r][c] < dp2[r + 1][c] && dp3[r][c + 1] > dp4[r + 1][c + 1]) {
                std::cout << "YES" << '\n';
                std::string ans(N, 'R');
                for(int i = 0; i <= r; i++) {
                    ans[rows[i]] = 'B'; 
                }
                std::cout << ans << ' ' << c + 1 << '\n';
                return;
            }
        }
    }

    std::cout << "NO" << '\n';
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
