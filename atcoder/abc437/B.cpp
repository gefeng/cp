#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W, N;
    std::cin >> H >> W >> N;

    std::vector<std::vector<int>> A(H, std::vector<int>(W, 0));
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> seen(100, 0);
    for(int i = 0; i < N; i++) {
        int X;
        std::cin >> X;
        seen[X] = 1;
    }

    int ans = 0;
    for(int i = 0; i < H; i++) {
        int cnt = 0;
        for(int j = 0; j < W; j++) {
            if(seen[A[i][j]]) {
                cnt += 1;
            }
        }

        ans = std::max(ans, cnt);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
