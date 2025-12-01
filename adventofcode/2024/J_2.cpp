#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

int64_t dfs(int n, int m, std::vector<std::string>& G, int r, int c, std::vector<std::vector<int64_t>>& dp) {
    if(G[r][c] == '9') {
        return 1;
    }

    if(dp[r][c] != -1) {
        return dp[r][c];
    }

    int res = 0;
    for(int d = 0; d < 4; d++) {
        int nr = r + DR[d];
        int nc = c + DC[d];
        if(nr >= 0 && nc >= 0 && nr < n && nc < m && G[nr][nc] == G[r][c] + 1) {
            res += dfs(n, m, G, nr, nc, dp); 
        }
    } 

    return dp[r][c] = res;
}

void run_case() {
    std::vector<std::string> G;
    for(std::string S; std::getline(std::cin, S); ) {
        G.push_back(S); 
    }

    int n = G.size();
    int m = G[0].size();
    
    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(G[i][j] == '0') {
                std::vector<std::vector<int64_t>> dp(n, std::vector<int64_t>(m, -1));
                ans += dfs(n, m, G, i, j, dp);
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
