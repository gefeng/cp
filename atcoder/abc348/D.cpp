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

    std::vector<std::vector<int>> G(H, std::vector<int>(W, 0));
    int sr = -1;
    int sc = -1;
    int tr = -1;
    int tc = -1;
    for(int i = 0; i < H; i++) {
        std::string S;
        std::cin >> S;

        for(int j = 0; j < W; j++) {
            if(S[j] == 'S') {
                sr = i;
                sc = j;
            } else if(S[j] == 'T') {
                tr = i;
                tc = j;
            } else if(S[j] == '#') {
                G[i][j] = -1;
            }
        }
    }

    int N;
    std::cin >> N;
    for(int i = 0; i < N; i++) {
        int R, C, E;
        std::cin >> R >> C >> E;
        R -= 1;
        C -= 1;
        G[R][C] = E;
    }

    std::queue<std::pair<int, int>> cur;
    std::vector<std::vector<int>> vis1(H, std::vector<int>(W, 0));

    if(G[sr][sc] == 0) {
        std::cout << "No" << '\n';
        return;
    }

    cur.emplace(sr, sc);
    vis1[sr][sc] = 1;
    
    while(!cur.empty()) {
        std::queue<std::pair<int, int>> nxt; 
        
        while(!cur.empty()) {
            auto [r, c] = cur.front();
            cur.pop();

            int e = G[r][c];
            std::queue<std::pair<int, int>> q;
            std::vector<std::vector<int>> vis2(H, std::vector<int>(W, 0));
            q.emplace(r, c);
            vis2[r][c] = 1;
            int d = 0;
            while(!q.empty() && d <= e) {
                int sz = q.size();
                while(sz--) {
                    auto [x, y] = q.front();
                    q.pop();
                    if(x == tr && y == tc) {
                        std::cout << "Yes" << '\n';
                        return;
                    }
                    if(G[x][y] > 0 && !vis1[x][y]) {
                        vis1[x][y] = 1;
                        nxt.emplace(x, y);
                    }

                    for(int i = 0; i < 4; i++) {
                        int nx = x + DR[i];
                        int ny = y + DC[i];
                        if(nx >= 0 && nx < H && ny >= 0 && ny < W && !vis2[nx][ny] && G[nx][ny] != -1) {
                            q.emplace(nx, ny);
                            vis2[nx][ny] = 1;
                        }
                    }
                }
                d += 1;
            }
        }

        std::swap(nxt, cur);
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
