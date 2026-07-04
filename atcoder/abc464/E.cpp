#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W, Q;
    std::cin >> H >> W >> Q;

    std::vector<std::vector<int>> ans(H + 1, std::vector<int>(W + 1, 0));
    std::vector<char> A(Q + 1);
    A[0] = 'A';
    for(int i = 0; i < Q; i++) {
        int R, C;
        char X;
        std::cin >> R >> C >> X;
        R--;
        C--;
        ans[R][C] = i + 1;
        A[i + 1] = X;
    }

    for(int i = H - 1; i >= 0; i--) {
        for(int j = W - 1; j >= 0; j--) {
            ans[i][j] = std::max(ans[i][j], std::max(ans[i + 1][j], ans[i][j + 1]));
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cout << A[ans[i][j]];
        }
        std::cout << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
