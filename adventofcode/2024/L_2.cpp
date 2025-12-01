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

int dfs(int n, int m, std::vector<std::string>& G, std::vector<std::vector<int>>& vis, int sr, int sc, int r, int c, std::vector<std::vector<std::vector<int>>>& side) {
    vis[r][c] = sr * m + sc;
    
    int area = 1;
    for(int i = 0; i < 4; i++) {
        int nr = r + DR[i];
        int nc = c + DC[i];
        if(nr >= 0 && nc >= 0 && nr < n & nc < m && G[nr][nc] == G[r][c]) {
            if(vis[nr][nc] == -1) {
                area += dfs(n, m, G, vis, sr, sc, nr, nc, side); 
            }
        } else {
            side[i][r][c] = G[r][c] - 'A';
        }
    }

    return area;
}

void run_case() {
    std::vector<std::string> G;
    for(std::string S; std::getline(std::cin, S); ) {
        G.push_back(S);
    } 

    int n = G.size();
    int m = G[0].size();

    std::vector<std::vector<int>> vis(n, std::vector<int>(m, -1));
    std::vector<std::vector<int>> area(n, std::vector<int>(m, 0));
    std::vector<std::vector<int>> len(n, std::vector<int>(m, 0));
    std::vector<std::vector<std::vector<int>>> side(4, std::vector<std::vector<int>>(n, std::vector<int>(m, -1)));

    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == -1) {
                int ret = dfs(n, m, G, vis, i, j, i, j, side); 
                area[i][j] = ret;
            }
        }
    }    

    for(int d = 1; d < 4; d += 2) {
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; ) {
                int k = c;
                while(c < m && side[d][r][c] == side[d][r][k]) {
                    c += 1;
                }
                if(side[d][r][k] != -1) {
                    int h = vis[r][k];
                    //std::cout << d << ' ' << r << ' ' << k << '\n';
                    len[h / m][h % m] += 1;
                }
            } 
        }
    }

    for(int d = 0; d < 3; d += 2) {
        for(int c = 0; c < m; c++) {
            for(int r = 0; r < n; ) {
                int k = r;
                while(r < n && side[d][r][c] == side[d][k][c]) {
                    r += 1;
                }
                if(side[d][k][c] != -1) {
                    int h = vis[k][c];
                    //std::cout << d << ' ' << r << ' ' << k << '\n';
                    len[h / m][h % m] += 1;
                }
            } 
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(area[i][j] != 0) {
                //std::cout << i << ' ' << j << ' ' << len[i][j] << '\n';
                ans += int64_t(area[i][j]) * len[i][j];
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
