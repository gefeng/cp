#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M, Q;
    std::cin >> N >> M >> Q;
    
    std::vector<std::vector<std::vector<int64_t>>> dp(2, std::vector<std::vector<int64_t>>(N, std::vector<int64_t>(M, 0)));
    
    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 2; k++) {
                dp[k][i][j] += 1;
                if(i && k == 1) {
                    dp[k][i][j] += dp[k ^ 1][i - 1][j];
                }
                if(j && k == 0) {
                    dp[k][i][j] += dp[k ^ 1][i][j - 1];
                }
                ans += dp[k][i][j];
            }
        }
    }

    std::vector<std::vector<int>> blocked(N, std::vector<int>(M, 0));
    int free = M * N;
    for(int i = 0; i < Q; i++) {
        int X, Y;
        std::cin >> X >> Y;
        X -= 1;
        Y -= 1;
        
        if(blocked[X][Y]) {
            dp[0][X][Y] = 1;
            dp[1][X][Y] = 1;
            if(Y - 1 >= 0) {
                dp[0][X][Y] += dp[1][X][Y - 1];
            }
            if(X - 1 >= 0) {
                dp[1][X][Y] += dp[0][X - 1][Y];
            }
            ans += dp[0][X][Y] + dp[1][X][Y];
            free += 1;
        } else {
            ans -= dp[0][X][Y] + dp[1][X][Y];
            dp[0][X][Y] = 0;
            dp[1][X][Y] = 0;
            free -= 1;
        }

        blocked[X][Y] ^= 1;
        
        int k = 0;
        int r = X;
        int c = Y + 1;
        while(r >= 0 && c >= 0 && r < N && c < M) {
            if(k == 0) {
                if(!blocked[r][c]) {
                    ans += dp[k ^ 1][r][c - 1] + 1 - dp[k][r][c];
                    dp[k][r][c] = 1 + dp[k ^ 1][r][c - 1];
                }
                r += 1;
            } else {
                if(!blocked[r][c]) {
                    ans += dp[k ^ 1][r - 1][c] + 1 - dp[k][r][c];
                    dp[k][r][c] = 1 + dp[k ^ 1][r - 1][c];
                }
                c += 1;
            }
            k ^= 1;
        }
        
        k = 1;
        r = X + 1;
        c = Y;
        while(r >= 0 && c >= 0 && r < N && c < M) {
            if(k == 0) {
                if(!blocked[r][c]) {
                    ans += dp[k ^ 1][r][c - 1] + 1 - dp[k][r][c];
                    dp[k][r][c] = 1 + dp[k ^ 1][r][c - 1];
                }
                r += 1;
            } else {
                if(!blocked[r][c]) {
                    ans += dp[k ^ 1][r - 1][c] + 1 - dp[k][r][c];
                    dp[k][r][c] = 1 + dp[k ^ 1][r - 1][c];
                }
                c += 1;
            }
            k ^= 1;
        }

        std::cout << ans - free << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
