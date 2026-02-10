#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

bool test_set_9 = false;

void run_case(int t, int T) {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    // if(T == 6561 && N == 2 && M == 4 && t == 1 && A[0][1] == 10 && A[0][2] == 10) {
    //     test_set_9 = true;
    // }
    // if(test_set_9 && t == 3402) {
    //     std::string s = std::to_string(N) + std::to_string(M);
    //     for(int i = 0; i < N; i++) {
    //         for(int j = 0; j < M; j++) {
    //             s += std::to_string(A[i][j]);
    //         }
    //     }
    //     std::cout << s << '\n';
    // }

    std::vector<std::vector<int64_t>> dp1(N, std::vector<int64_t>(M, -INF));
    std::vector<std::vector<int64_t>> dp2(N, std::vector<int64_t>(M, -INF));
    std::vector<std::pair<int, int>> path;
    dp1[0][0] = A[0][0];
    dp2[N - 1][M - 1] = A[N - 1][M - 1];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i - 1 >= 0) {
                dp1[i][j] = std::max(dp1[i][j], dp1[i - 1][j] + A[i][j]);
            }
            if(j - 1 >= 0) {
                dp1[i][j] = std::max(dp1[i][j], dp1[i][j - 1] + A[i][j]);
            }
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        for(int j = M - 1; j >= 0; j--) {
            if(i + 1 < N) {
                dp2[i][j] = std::max(dp2[i][j], dp2[i + 1][j] + A[i][j]);
            }
            if(j + 1 < M) {
                dp2[i][j] = std::max(dp2[i][j], dp2[i][j + 1] + A[i][j]);
            }
        }
    }

    // recover best path
    {
        int r = N - 1;
        int c = M - 1;
        while(true) {
            path.emplace_back(r, c);
            if(r == 0 && c == 0) {
                break;
            }
 
            if(r == 0) {
                c -= 1;
            } else if(c == 0) {
                r -= 1;
            } else {
                if(dp1[r - 1][c] >= dp1[r][c - 1]) {
                    r -= 1;
                } else {
                    c -= 1;
                }
            }
        }
        std::ranges::reverse(path);
    }

    // prefix max of each row
    std::vector<std::vector<int64_t>> dp3(N, std::vector<int64_t>(M, -INF)); 
    // prefix max of each col
    std::vector<std::vector<int64_t>> dp4(M, std::vector<int64_t>(N, -INF)); 
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int64_t now = dp1[i][j] + dp2[i][j] - A[i][j];
            dp3[i][j] = j - 1 >= 0 ? std::max(dp3[i][j - 1], now) : now;
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            int64_t now = dp1[j][i] + dp2[j][i] - A[j][i];
            dp4[i][j] = j - 1 >= 0 ? std::max(dp4[i][j - 1], now) : now;
        }
    }

    int64_t ans = dp1[N - 1][M - 1];
    for(auto [r, c] : path) {
        int64_t score = dp1[N - 1][M - 1] - A[r][c] * 2;
        if(r - 1 >= 0 && c + 1 < M) {
            score = std::max(score, dp4[c + 1][r - 1]);
        }
        if(r + 1 < N && c - 1 >= 0) {
            score = std::max(score, dp3[r + 1][c - 1]);
        }
        ans = std::min(ans, score);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    for(int i = 1; i <= T; i++) {
        run_case(i, T);
    }
    // while(T--) {
    //     run_case();
    // }
}
