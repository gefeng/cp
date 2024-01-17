#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

std::array<int, 4> DR = {0, 1, 0, -1};
std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> ans(N, std::vector<int>(N, -1));
    int r = 0;
    int c = 0;
    int d = 0;
    int v = 1;
    while(v != N * N) {
        ans[r][c] = v++;
        int nr = r + DR[d];
        int nc = c + DC[d];
        
        if(nr < 0 || nc < 0 || nr >= N || nc >= N || ans[nr][nc] != -1) {
            d = (d + 1) % 4;
            nr = r + DR[d];
            nc = c + DC[d];
        }
    
        std::swap(r, nr);
        std::swap(c, nc);
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == N / 2 && j == N / 2) {
                std::cout << 'T' << ' ';
            } else {
                std::cout << ans[i][j] << " \n"[j == N - 1];
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
