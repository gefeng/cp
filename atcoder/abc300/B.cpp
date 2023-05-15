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

    std::vector<std::string> A(H);
    std::vector<std::string> B(H);

    for(int i = 0; i < H; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < H; i++) {
        std::cin >> B[i];
    }

    auto validate = [&](int i, int j) {
        std::vector<std::string> AA(A);
        
        for(int r = 0; r < H; r++) {
            for(int c = 0; c < W; c++) {
                int nr = (r - i + H) % H;
                int nc = (c - j + W) % W;
                AA[nr][nc] = A[r][c];
            }
        }

        for(int r = 0; r < H; r++) {
            for(int c = 0; c < W; c++) {
                if(AA[r][c] != B[r][c]) {
                    return false;
                }
            }
        }

        return true;
    };

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(validate(i, j)) {
                std::cout << "Yes" << '\n';
                return;
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
