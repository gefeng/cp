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

int dfs(int N, int M, std::vector<std::vector<int>>& G, std::vector<std::vector<bool>>& vis, int r, int c) {
    int res = G[r][c];
    vis[r][c] = true;
    
    for(int i = 0; i < 4; i++) {
        int nr = r + DR[i];
        int nc = c + DC[i];
        if(nr >= 0 && nc >= 0 && nr < N && nc < M && !vis[nr][nc] && G[nr][nc] != 0) {
            res += dfs(N, M, G, vis, nr, nc);
        }
    }

    return res;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N, std::vector<int>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> G[i][j];
        }
    }

    int ans = 0;
    std::vector<std::vector<bool>> vis(N, std::vector<bool>(M, false));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(G[i][j] != 0 && !vis[i][j]) {
                ans = std::max(ans, dfs(N, M, G, vis, i, j));
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
