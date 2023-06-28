#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    int max_r = 0;
    int min_r = H;
    int max_c = 0;
    int min_c = W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '#') {
                min_r = std::min(min_r, i);
                max_r = std::max(max_r, i);
                min_c = std::min(min_c, j);
                max_c = std::max(max_c, j);
            }
        }
    }

    for(int r = min_r; r <= max_r; r++) {
        for(int c = min_c; c <= max_c; c++) {
            if(G[r][c] == '.') {
                std::cout << r + 1 << ' ' << c + 1 << '\n';
                return;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
