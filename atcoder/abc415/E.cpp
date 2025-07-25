#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MAX = static_cast<int64_t>(1e18);
constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::vector<int>> G(H, std::vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> G[i][j];
        }
    }

    int n = H + W - 1;
    std::vector<int> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    int64_t lo = 0;
    int64_t hi = MAX;
    int64_t ans = -1;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;
        
        std::vector<std::vector<int64_t>> dp(H, std::vector<int64_t>(W, -INF));
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                if(i == 0 && j == 0) {
                    int64_t bal = mid + G[0][0] - A[0];
                    if(bal >= 0) {
                        dp[0][0] = bal;
                    }
                    continue;
                }

                if(i && dp[i - 1][j] >= 0) {
                    int64_t bal = dp[i - 1][j] + G[i][j] - A[i + j];
                    if(bal >= 0) {
                        dp[i][j] = std::max(dp[i][j], bal);
                    }
                }
                if(j && dp[i][j - 1] >= 0) {
                    int64_t bal = dp[i][j - 1] + G[i][j] - A[i + j];
                    if(bal >= 0) {
                        dp[i][j] = std::max(dp[i][j], bal);
                    }
                }
            }
        }

        if(dp[H - 1][W - 1] >= 0) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
