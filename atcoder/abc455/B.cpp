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
    for(int i = 0; i < H; i++) {
        std::cin >> A[i];
    }

    auto check = [&](int r1, int c1, int r2, int c2) {
        for(int i = r1; i <= r2; i++) {
            for(int j = c1; j <= c2; j++) {
                if(A[i][j] != A[r1 + r2 - i][c1 + c2 - j]) {
                    return false;
                }
            }
        }
        return true;
    };

    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            for(int r = i; r < H; r++) {
                for(int c = j; c < W; c++) {
                    if(check(i, j, r, c)) {
                        ans++;
                    }
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
