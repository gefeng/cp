#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {-1, 0, 1, 0};
constexpr std::array<int, 4> DC = {0, 1, 0, -1};

bool dfs(int n, int m, std::vector<std::string>& g, int r, int c, int d, std::vector<std::vector<std::vector<int>>>& vis) {
    vis[d][r][c] = 1;

    int nr = r + DR[d];
    int nc = c + DC[d];
    if(nr < 0 || nc < 0 || nr >= n || nc >= m) {
        return true;
    }

    if(g[nr][nc] != '#') {
        if(!vis[d][nr][nc]) {
            if(dfs(n, m, g, nr, nc, d, vis)) {
                return true;
            }
        }
    } else {
        d = (d + 1) % 4;
        if(!vis[d][r][c]) {
            if(dfs(n, m, g, r, c, d, vis)) {
                return true;
            }
        }
    }

    return false;
}

void run_case() {
    std::vector<std::string> g;
    for(std::string S; std::getline(std::cin, S); ) {
        g.push_back(S); 
    }

    int n = g.size();
    int m = g[0].size();
    int sr = -1;
    int sc = -1;
    int d = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(g[i][j] != '#' && g[i][j] != '.') {
                sr = i;
                sc = j;
            }
        } 
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(g[i][j] == '.') {
                g[i][j] = '#';
                std::vector<std::vector<std::vector<int>>> vis(4, std::vector<std::vector<int>>(n, std::vector<int>(m, 0)));
                if(!dfs(n, m, g, sr, sc, d, vis)) {
                    ans += 1; 
                }
                g[i][j] = '.';
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
