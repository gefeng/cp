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

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    int sr = -1;
    int sc = -1;
    int tr = -1;
    int tc = -1;
    for(int r = 0; r < H; r++) {
        for(int c = 0; c < W; c++) {
            if(G[r][c] == 'S') {
                sr = r;
                sc = c;
                G[r][c] = '.';
            }
            if(G[r][c] == 'G') {
                tr = r;
                tc = c;
                G[r][c] = '.';
            }
        }
    } 

    std::queue<std::array<int, 3>> q;
    std::vector<std::vector<std::vector<int>>> vis(2, std::vector<std::vector<int>>(H, std::vector<int>(W, 0)));
    
    q.push({sr, sc, 0});
    q.push({sr, sc, 1});
    vis[0][sr][sc] = 1;
    vis[1][sr][sc] = 1;

    int dist = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            std::array<int, 3> now = q.front();
            q.pop();
            
            int r = now[0];
            int c = now[1];
            int f = now[2];

            if(r == tr && c == tc) {
                std::cout << dist << '\n';
                return;
            }

            for(int d = f, i = 0; i < 2; d = (d + 2) % 4, i++) {
                int nr = r + DR[d];
                int nc = c + DC[d];
                int nf = f ^ 1;
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] == '.' && !vis[nf][nr][nc]) {
                    vis[nf][nr][nc] = 1;
                    q.push({nr, nc, nf});
                }
            }
        }
        dist += 1;
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
