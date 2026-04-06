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

    std::vector<std::string> ans(H, std::string(W, '.'));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(i == 0 || j == 0 || i == H - 1 || j == W - 1) {
                ans[i][j] = '#';
            }
        }
    }

    for(int i = 0; i < H; i++) {
        std::cout << ans[i] << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
