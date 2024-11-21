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

int64_t dfs(int H, int W, std::vector<std::string>& G, std::vector<std::vector<int>>& vis, int r, int c, int k) {
    if(k == 0) {
        return 1;
    }

    vis[r][c] = 1;

    int64_t res = 0;
    for(int d = 0; d < 4; d++) {
        int nr = r + DR[d];
        int nc = c + DC[d];
        if(nr >= 0 && nc >= 0 && nr < H && nc < W && !vis[nr][nc] && G[nr][nc] != '#') {
            res += dfs(H, W, G, vis, nr, nc, k - 1); 
        }
    }

    vis[r][c] = 0;

    return res;
}

void run_case() {
    int H, W, K;
    std::cin >> H >> W >> K;
    
    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    int64_t ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '.') {
                std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));
                int64_t cnt = dfs(H, W, G, vis, i, j, K);
                ans += cnt;
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
