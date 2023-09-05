#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> G(N, std::vector<int>(4, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 4; j++) {
            std::cin >> G[i][j];
        }
    }
    
    std::vector<std::vector<int>> a(200, std::vector<int>(200, 0));
    for(int i = 0; i < N; i++) {
        for(int r = G[i][2]; r < G[i][3]; r++) {
            for(int c = G[i][0]; c < G[i][1]; c++) {
                a[r][c] += 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            if(a[i][j] >= 1) {
                ans += 1;
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
