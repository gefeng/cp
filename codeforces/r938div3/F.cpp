#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

constexpr int MAX = 200;
std::vector<std::vector<std::vector<int>>> dp;

void run_case() {
    std::array<int, 4> A{};
    for(int i = 0; i < 4; i++) {
        std::cin >> A[i];
    }

    std::cout << dp[A[0]][A[1]][A[2]] + A[3] / 2 - 1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    dp = std::vector<std::vector<std::vector<int>>>(MAX + 1, std::vector<std::vector<int>>(MAX + 1, std::vector<int>(MAX + 1, 0)));
    auto win = [](int a, int b, int c) {
        return a % 2 == b % 2 && b % 2 == c % 2;
    };

    dp[0][0][0] = 1;
    for(int i = 0; i <= MAX; i++) {
        for(int j = 0; j <= MAX; j++) {
            for(int k = 0; k <= MAX; k++) {
                if(i + 1 <= MAX) {
                    dp[i + 1][j][k] = std::max(dp[i + 1][j][k], dp[i][j][k] + (win(i + 1, j, k) ? 1 : 0));
                }
                if(j + 1 <= MAX) {
                    dp[i][j + 1][k] = std::max(dp[i][j + 1][k], dp[i][j][k] + (win(i, j + 1, k) ? 1 : 0));
                }
                if(k + 1 <= MAX) {
                    dp[i][j][k + 1] = std::max(dp[i][j][k + 1], dp[i][j][k] + (win(i, j, k + 1) ? 1 : 0));
                }
            }
        }
    }
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
