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
    
    std::vector<std::string> A(H);
    for(int i = 0; i < H; i++) {
        std::cin >> A[i];
    }

    auto check = [&](int r, int c) {
        int cnt = 0;
        for(int d = 0; d < 4; d++) {
            int nr = r + DR[d];
            int nc = c + DC[d];
            if(nr >= 0 && nc >= 0 && nr < H && nc < W && A[nr][nc] == '#') {
                cnt += 1;
            }
        }
        return cnt == 1;
    };

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> vis(H, std::vector<int>(W, 0));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] == '.') {
                if(check(i, j)) {
                    q.emplace(i, j);
                    vis[i][j] = 1;
                }
            }
        }
    }

    while(!q.empty()) {
        int size = q.size();
        std::vector<std::pair<int, int>> a;
        while(size--) {
            auto [r, c] = q.front();
            q.pop();
            a.emplace_back(r, c);
            A[r][c] = '#';
        }

        for(auto [r, c] : a) {
            for(int d = 0; d < 4; d++) {
                int nr = r + DR[d];
                int nc = c + DC[d];
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && !vis[nr][nc] && A[nr][nc] == '.' && check(nr, nc)) {
                    q.emplace(nr, nc);
                    vis[nr][nc] = 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            ans += A[i][j] == '#' ? 1 : 0;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
