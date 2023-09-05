#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

int64_t dfs(int N, std::vector<std::vector<int>>& G, int used, std::vector<int64_t>& dp) {
    int cnt = __builtin_popcount(used);
    if(cnt < 2) {
        return 0;
    }

    if(dp[used] != -1) {
        return dp[used];
    }

    int64_t res = 0;
    for(int v = 0; v < N; v++) {
        if(used & (1 << v)) {
            for(int u = 0; u < N; u++) {
                if((used & (1 << u)) && u != v) {
                    res = std::max(res, dfs(N, G, used ^ (1 << u) ^ (1 << v), dp) + G[u][v]);
                }
            }
            used ^= 1 << v;
        }
    } 

    return dp[used] = res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N, std::vector<int>(N, 0));
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int W;
            std::cin >> W;

            G[i][j] = W;
            G[j][i] = W;
        }
    }

    std::vector<int64_t> dp(1 << N, -1);
    dfs(N, G, (1 << N) - 1, dp);

    int64_t ans = 0;
    for(int i = 0; i < (1 << N); i++) {
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
