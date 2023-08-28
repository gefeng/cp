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

    int sr = 0;
    int sc = 0;
    int tr = 0;
    int tc = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == 'S') {
                sr = i;
                sc = j;
                G[i][j] = '.';
            } else if(G[i][j] == 'G') {
                tr = i;
                tc = j;
                G[i][j] = '.';
            }
        }
    }

    std::vector<std::vector<int>> a(H, std::vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; ) {
            if(G[i][j] == '>') {
                j += 1;
                while(j < W && G[i][j] == '.') {
                    a[i][j] = 1;
                    j += 1;
                }
            } else {
                j += 1;
            }
        }

        for(int j = W - 1; j >= 0; ) {
            if(G[i][j] == '<') {
                j -= 1;
                while(j >= 0 && G[i][j] == '.') {
                    a[i][j] = 1;
                    j -= 1;
                }
            } else {
                j -= 1;
            }
        }
    }

    for(int i = 0; i < W; i++) {
        for(int j = 0; j < H; ) {
            if(G[j][i] == 'v') {
                j += 1;
                while(j < H && G[j][i] == '.') {
                    a[j][i] = 1;
                    j += 1;
                }     
            } else {
                j += 1;
            }
        }
        
        for(int j = H - 1; j >= 0; ) {
            if(G[j][i] == '^') {
                j -= 1;
                while(j >= 0 && G[j][i] == '.') {
                    a[j][i] = 1;
                    j -= 1;
                }     
            } else {
                j -= 1;
            }
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(a[i][j] == 1) {
                G[i][j] = '#';
            }
            if(G[i][j] == '>' || G[i][j] == '<' || G[i][j] == 'v' || G[i][j] == '^') {
                G[i][j] = '#';
            }
        }
    }

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));
    q.emplace(sr, sc);
    vis[sr][sc] = 1;
    int ans = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto [r, c] = q.front();
            q.pop();

            if(r == tr && c == tc) {
                std::cout << ans << '\n';
                return;
            }

            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && !vis[nr][nc] && G[nr][nc] != '#') {
                    q.emplace(nr, nc);
                    vis[nr][nc] = 1;
                }
            }
        }
        ans += 1;
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
