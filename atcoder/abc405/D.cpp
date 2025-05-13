#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};
constexpr std::array<char, 4> ARROW = {'<', '^', '>', 'v'};

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> A(H);
    for(int i = 0; i < H; i++) {
        std::cin >> A[i];
    }

    std::queue<std::pair<int, int>> q;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] == 'E') {
                q.emplace(i, j);
            }
        }
    }

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + DR[i];
                int nc = c + DC[i];
                if(nr >= 0 && nc >= 0 && nr < H && nc < W && A[nr][nc] == '.') {
                    q.emplace(nr, nc);
                    A[nr][nc] = ARROW[i]; 
                }
            }
        }
    }

    for(int i = 0; i < H; i++) {
        std::cout << A[i] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
