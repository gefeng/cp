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

void dfs(int n, int m, std::vector<std::string>& g, int r, int c, int d, int& ans) {
    if(g[r][c] != 'x') {
        g[r][c] = 'x';
        ans += 1;
    }

    int nr = r + DR[d];
    int nc = c + DC[d];
    if(nr < 0 || nc < 0 || nr >= n || nc >= m) {
        return;
    }

    if(g[nr][nc] != '#') {
        dfs(n, m, g, nr, nc, d, ans);
    } else {
        d = (d + 1) % 4;
        dfs(n, m, g, r, c, d, ans);
    }
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

    dfs(n, m, g, sr, sc, d, ans);

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
