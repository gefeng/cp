#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> row(N, std::vector<int>(N, 0));
    std::vector<std::vector<int>> col(N, std::vector<int>(N, 0));

    for(int r = 0; r < N; r++) {
        int now = 0;
        for(int c = N - 1; c >= 0; c--) {
            now += A[r][c] == '#' ? 1 : 0;
            row[r][c] = now; 
        }
    }
    
    for(int c = 0; c < N; c++) {
        int now = 0;
        for(int r = 0; r < N; r++) {
            now += A[r][c] == '#' ? 1 : 0;
            col[c][r] = now;
        }
    }

    std::vector<std::vector<std::vector<int>>> dp(2, std::vector<std::vector<int>>(N, std::vector<int>(N, INF)));
    int ans = INF;
    for(int r = N - 1; r >= 0; r--) {
        for(int c = 0; c < N; c++) {
            if(r == N - 1 && c == 0) {
                dp[0][r][c] = col[c][r];
                dp[1][r][c] = N - row[r][c];
            } else {
                if(c - 1 >= 0) {
                    dp[0][r][c] = std::min(dp[0][r][c], dp[0][r][c - 1] + col[c][r]);
                    dp[1][r][c] = std::min(dp[1][r][c], dp[0][r][c - 1] + N - c - row[r][c]);
                }
                if(r + 1 < N) {
                    dp[0][r][c] = std::min(dp[0][r][c], dp[1][r + 1][c] + col[c][r]);
                    dp[1][r][c] = std::min(dp[1][r][c], dp[1][r + 1][c] + N - c - row[r][c]);
                }
            }

            if(r == 0) {
                ans = std::min(ans, dp[1][r][c]);
            }
            if(c == N - 1) {
                ans = std::min(ans, dp[0][r][c]);
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
