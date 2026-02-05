#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, C;
    std::cin >> N >> C;
    C -= 1;
    
    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(N, 0));
    std::vector<int> col(N, 1);

    dp[N - 1][C] = 1;
    for(int c = 0; c < N; c++) {
        if(A[N - 1][c] == '#') {
            col[c] = 0;
        }
    }

    for(int r = N - 2; r >= 0; r--) {
        for(int c = 0; c < N; c++) {
            for(int d = -1; d < 2; d++) {
                int pc = c + d;
                if(pc >= 0 && pc < N) {
                    if(A[r][c] == '#') {
                        dp[r][c] = dp[r][c] || (dp[r + 1][pc] && col[c]);
                    } else {
                        dp[r][c] = dp[r][c] || dp[r + 1][pc];
                    }
                }
            }
        }

        for(int c = 0; c < N; c++) {
            if(A[r][c] == '#' && !dp[r][c]) {
                col[c] = 0;
            }
        }
    }

    std::string ans(N, '0');
    for(int c = 0; c < N; c++) {
        if(dp[0][c]) {
            ans[c] = '1';
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
