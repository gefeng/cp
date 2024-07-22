#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr int INF = int(2e9);
constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int H, W, Y;
    std::cin >> H >> W >> Y;

    std::vector<std::vector<int>> G(H, std::vector<int>(W));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> G[i][j];
        }
    }

    std::vector<std::vector<int>> when(H, std::vector<int>(W, INF));
    std::vector<std::queue<std::pair<int, int>>> a(Y + 1); 
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(i == 0 || j == 0 || i == H - 1 || j == W - 1) {
                if(G[i][j] <= Y) {
                    a[G[i][j]].emplace(i, j);
                }
            }
        }
    }

    for(int d = 1; d <= Y; d++) {
        while(!a[d].empty()) {
            auto [r, c] = a[d].front();
            a[d].pop();
            when[r][c] = d;
            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && when[nr][nc] == INF) {
                    if(G[nr][nc] <= d) {
                        when[nr][nc] = d;
                        a[d].emplace(nr, nc);
                    } else if(G[nr][nc] <= Y) {
                        a[G[nr][nc]].emplace(nr, nc);
                    }
                }
            }
        }
    }

    std::vector<int> ans(Y + 1, 0);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(when[i][j] <= Y) {
                ans[when[i][j]] -= 1;
            }
        }
    }

    int now = H * W;
    for(int i = 1; i <= Y; i++) {
        now += ans[i];
        std::cout << now << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
