#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

constexpr int INF = int(2e9);
constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int H, W, A, B, C, D;
    std::cin >> H >> W;
    
    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    std::cin >> A >> B >> C >> D;
    A -= 1;
    B -= 1;
    C -= 1;
    D -= 1;

    std::deque<std::tuple<int, int, int>> q;
    std::vector<std::vector<int>> best(H, std::vector<int>(W, INF));
    q.emplace_back(A, B, 0);
    best[A][B] = 0;
    while(!q.empty()) {
        auto [r, c, d] = q.front();
        q.pop_front();

        if(best[r][c] != d) {
            continue;
        }

        if(r == C && c == D) {
            std::cout << d << '\n';
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
                int nd = d;
                if(G[nr][nc] == '#') {
                    nd += 1; 
                    if(best[nr][nc] > nd) {
                        best[nr][nc] = nd; 
                        q.emplace_back(nr, nc, nd);
                    }
                    nr += DR[i];
                    nc += DC[i];
                    if(nr >= 0 && nc >= 0 && nr < H && nc < W) {
                        if(best[nr][nc] > nd) {
                            best[nr][nc] = nd;
                            q.emplace_back(nr, nc, nd);
                        }
                    }
                } else {
                    if(best[nr][nc] > nd) {
                        best[nr][nc] = nd;
                        q.emplace_front(nr, nc, nd);
                    }
                }
            }
        } 
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
