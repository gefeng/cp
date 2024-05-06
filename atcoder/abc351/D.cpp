#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

int dfs(int H, int W, std::vector<std::string>& G, std::vector<std::vector<int>>& vis, std::set<std::pair<int, int>>& s, int r, int c) {
    int res = 1;
    vis[r][c] = 1;
    
    for(int d = 0; d < 4; d++) {
        int nr = r + DR[d];
        int nc = c + DC[d];
        if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
            if(G[nr][nc] == '0' && s.find({nr, nc}) == s.end()) {
                res += 1;
                s.emplace(nr, nc);
            }
            if(G[nr][nc] == '.' && !vis[nr][nc]) {
                res += dfs(H, W, G, vis, s, nr, nc); 
            }
        }
    }

    return res;
}

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    auto next_to_magnet = [&](int r, int c) {
        for(int d = 0; d < 4; d++) {
            int nr = r + DR[d];
            int nc = c + DC[d];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] == '#') {
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] != '#') {
                if(next_to_magnet(i, j)) {
                    ans = 1;
                    G[i][j] = '0';
                }
            }
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '.' && !vis[i][j]) {
                std::set<std::pair<int, int>> s;
                int res = dfs(H, W, G, vis, s, i, j);
                ans = std::max(ans, res);
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
