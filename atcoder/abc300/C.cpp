#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

const std::array<int, 4> DR = {1, -1, 1, -1};
const std::array<int, 4> DC = {1, -1, -1, 1};

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    int n = std::min(H, W);
    std::vector<int> ans(n, 0);

    for(int r = 0; r < H; r++) {
        for(int c = 0; c < W; c++) {
            if(G[r][c] == '.') {
                continue;
            }

            int sz = n;
            for(int d = 0; d < 4; d++) {
                int nr = r;
                int nc = c;
                int len = 0;
                while(nr >= 0 && nc >= 0 && nr < H && nc < W && G[nr][nc] == '#') {
                    len += 1; 
                    nr += DR[d];
                    nc += DC[d];
                }

                sz = std::min(sz, len);
            }

            if(sz > 1) {
                ans[sz - 2] += 1;
            }
        }
    } 

    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
