#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {-1, 0, 1, 0};
constexpr std::array<int, 4> DC = {0, 1, 0, -1};

void run_case() {
    int W, H, N;
    std::cin >> H >> W >> N;

    int d = 0;
    int r = 0;
    int c = 0;
    std::vector<std::vector<int>> ans(H, std::vector<int>(W, 0));
    for(int i = 0; i < N; i++) {
        if(ans[r][c] == 0) {
            ans[r][c] = 1;
            d += 1;
            d %= 4;
        } else {
            ans[r][c] = 0;
            d -= 1;
            d += 4;
            d %= 4;
        }
        r += DR[d];
        c += DC[d]; 
        r = (r + H) % H;
        c = (c + W) % W;
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cout << (ans[i][j] == 0 ? '.' : '#');
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
