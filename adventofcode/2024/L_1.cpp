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

std::pair<int, int> dfs(int n, int m, std::vector<std::string>& G, std::vector<std::vector<int>>& vis, int r, int c) {
    vis[r][c] = 1;
    
    int area = 1;
    int perimeter = 4;
    for(int i = 0; i < 4; i++) {
        int nr = r + DR[i];
        int nc = c + DC[i];
        if(nr >= 0 && nc >= 0 && nr < n & nc < m && G[nr][nc] == G[r][c]) {
            perimeter -= 1;
            
            if(!vis[nr][nc]) {
                auto [a, p] = dfs(n, m, G, vis, nr, nc); 
                perimeter += p;
                area += a;
            }
        }
    }

    return {area, perimeter};
}

void run_case() {
    std::vector<std::string> G;
    for(std::string S; std::getline(std::cin, S); ) {
        G.push_back(S);
    } 

    int n = G.size();
    int m = G[0].size();

    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    int64_t ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j]) {
                auto [a, p] = dfs(n, m, G, vis, i, j); 
                ans += int64_t(a) * p;
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
