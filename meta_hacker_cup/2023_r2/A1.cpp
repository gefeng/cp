#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

const std::array<int, 4> DR = {0, 1, 0, -1};
const std::array<int, 4> DC = {1, 0, -1, 0};

bool dfs(int H, int W, std::vector<std::string>& G, std::vector<std::vector<int>>& vis, int r, int c) {
    vis[r][c] = 1;

    bool res = true;
    for(int d = 0; d < 4; d++) {
        int nr = r + DR[d];
        int nc = c + DC[d]; 
        if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
            if(G[nr][nc] == '.') {
                res = false;
            }
        }
    }

    for(int d = 0; d < 4; d++) {
        int nr = r + DR[d];
        int nc = c + DC[d]; 
        if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
            if(G[nr][nc] == 'W' && !vis[nr][nc]) {
                res = dfs(H, W, G, vis, nr, nc) && res;
            }
        }
    }

    return res;
}

bool is_captured(int H, int W, std::vector<std::string>& G) {
    std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(!vis[i][j] && G[i][j] == 'W') {
                if(dfs(H, W, G, vis, i, j)) {
                    return true;
                }
            }
        }
    }

    return false;
}

void run_case(int T) {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '.') {
                G[i][j] = 'B';
                if(is_captured(H, W, G)) {
                    std::cout << "Case #" << T << ": YES" << '\n';
                    return; 
                }
                G[i][j] = '.';
            } 
        }
    }

    std::cout << "Case #" << T << ": NO" << '\n';
}

int main() {
    int T;
    std::cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
