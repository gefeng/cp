#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

const std::array<int, 4> DR = {0, 1, 0, -1};
const std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    if(G[0][0] != 's') {
        std::cout << "No" << '\n';
        return;
    }

    std::string snuke = "snuke";
    
    std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));
    std::queue<std::tuple<int, int, int>> q;

    q.emplace(0, 0, 0);
    vis[0][0] = 1;

    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto [r, c, i] = q.front();
            q.pop();

            if(r == H - 1 && c == W - 1) {
                std::cout << "Yes" << '\n';
                return;
            }

            for(int d = 0; d < 4; d++) {
                int nr = r + DR[d];
                int nc = c + DC[d];

                if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
                    int ni = (i + 1) % 5;
                    if(G[nr][nc] == snuke[ni] && !vis[nr][nc]) {
                        vis[nr][nc] = 1;
                        q.emplace(nr, nc, ni);
                    }
                }
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
