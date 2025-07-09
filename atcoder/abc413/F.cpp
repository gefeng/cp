#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr int INF = int(2e9);

void run_case() {
    int H, W, K;
    std::cin >> H >> W >> K;

    std::vector<std::pair<int, int>> A(K);
    for(int i = 0; i < K; i++) {
        std::cin >> A[i].first >> A[i].second;
        A[i].first -= 1;
        A[i].second -= 1;
    }

    std::vector<std::vector<int>> g(H, std::vector<int>(W, INF));
    std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));
    
    std::queue<std::pair<int, int>> q;
    for(auto [r, c] : A) {
        g[r][c] = 0;
        q.emplace(r, c);
    }

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        
        for(int d = 0; d < 4; d++) {
            int n_r = r + DR[d];
            int n_c = c + DC[d];
            if(n_r >= 0 && n_c >= 0 && n_r < H && n_c < W && g[n_r][n_c] == INF) {
                if(vis[n_r][n_c]) {
                    g[n_r][n_c] = g[r][c] + 1;
                    q.emplace(n_r, n_c);
                } else {
                    vis[n_r][n_c] = 1;
                } 
            }
        }
    }

    int64_t ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            ans += g[i][j] != INF ? g[i][j] : 0;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
