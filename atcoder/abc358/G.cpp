#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int H, W, K, SR, SC;
    std::cin >> H >> W >> K >> SR >> SC;
    SR -= 1;
    SC -= 1;

    std::vector<std::vector<int>> G(H, std::vector<int>(W, 0));
    int max_v = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> G[i][j];
            max_v = std::max(max_v, G[i][j]);
        }
    }

    std::vector<std::vector<int64_t>> dp(H, std::vector<int64_t>(W, -1));
    dp[SR][SC] = 0;
    
    int steps = std::min(K, H * W);
    for(int d = 1; d <= steps; d++) {
        std::vector<std::vector<int64_t>> ndp(H, std::vector<int64_t>(W, -1));
    
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(dp[i][j] != -1) {
                    if(G[i][j] == max_v) {
                        ndp[i][j] = std::max(ndp[i][j], dp[i][j] + max_v);
                    } else {
                        ndp[i][j] = std::max(ndp[i][j], dp[i][j] + G[i][j]);
                        for(int k = 0; k < 4; k++) {
                            int ni = i + DR[k];
                            int nj = j + DC[k];
                            if(ni >= 0 && nj >= 0 && ni < H && nj < W) {
                                ndp[ni][nj] = std::max(ndp[ni][nj], dp[i][j] + G[ni][nj]);
                            }
                        }
                    }
                }
            }
        }

        std::swap(dp, ndp);
    }

    int64_t ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(dp[i][j] != -1) {
                ans = std::max(ans, dp[i][j] + (int64_t)(K - steps) * G[i][j]);
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
