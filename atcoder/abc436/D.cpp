#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr std::array<int, 4> DR{0, 1, 0, -1};
constexpr std::array<int, 4> DC{1, 0, -1, 0};

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> A(H);
    for(int i = 0; i < H; i++) {
        std::cin >> A[i];
    }

    std::vector<std::vector<std::pair<int, int>>> warp(26);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] >= 'a' && A[i][j] <= 'z') {
                warp[A[i][j] - 'a'].emplace_back(i, j);
            }
        }
    }

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));
    std::vector<int> first(26, 0);
    int d = 0;
    q.emplace(0, 0);
    vis[0][0] = 1;

    if(A[0][0] >= 'a' && A[0][0] <= 'z') {
        first[A[0][0] - 'a'] = 1;
    }

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [r, c] = q.front();
            q.pop();
            
            if(r == H - 1 && c == W - 1) {
                std::cout << d << '\n';
                return;
            }

            for(int d = 0; d < 4; d++) {
                int nr = r + DR[d];
                int nc = c + DC[d];
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && A[nr][nc] != '#' && !vis[nr][nc]) {
                    q.emplace(nr, nc);
                    vis[nr][nc] = 1;
                    if(A[nr][nc] >= 'a' && A[nr][nc] <= 'z' && !first[A[nr][nc] - 'a']) {
                        first[A[nr][nc] - 'a'] = 1;
                    }
                }
            }

            if(A[r][c] >= 'a' && A[r][c] <= 'z') {
                if(first[A[r][c] - 'a'] == 1) {
                    first[A[r][c] - 'a'] = 2;
                    for(auto [nr, nc] : warp[A[r][c] - 'a']) {
                        if(!vis[nr][nc]) {
                            vis[nr][nc] = 1;
                            q.emplace(nr, nc);
                        }
                    }
                } 
            }
        }
        d += 1;
    }

    std::cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
