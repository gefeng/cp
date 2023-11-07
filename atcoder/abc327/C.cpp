#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::vector<std::vector<int>> G(9, std::vector<int>(9, 0));
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            std::cin >> G[i][j];
        }
    }

    for(int i = 0; i < 9; i++) {
        std::array<int, 10> cnt = {};
        for(int j = 0; j < 9; j++) {
            cnt[G[i][j]] += 1;
        }
        for(int j = 1; j <= 9; j++) {
            if(cnt[j] != 1) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    for(int i = 0; i < 9; i++) {
        std::array<int, 10> cnt = {};
        for(int j = 0; j < 9; j++) {
            cnt[G[j][i]] += 1;
        }
        for(int j = 1; j <= 9; j++) {
            if(cnt[j] != 1) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    for(int i = 0; i < 9; i++) {
        std::array<int, 10> cnt = {};
        
        int r = (i / 3) * 3;
        int c = (i % 3) * 3;

        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                cnt[G[r + j][c + k]] += 1;
            }
        }

        for(int j = 1; j <= 9; j++) {
            if(cnt[j] != 1) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
