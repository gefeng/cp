#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> G(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> G[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            bool ok = true;
            int max_v = 0;
            for(int d = 0; d < 4; d++) {
                int ni = i + DR[d];
                int nj = j + DC[d];
                if(ni >= 0 && nj >= 0 && ni < N && nj < M) {
                    max_v = std::max(max_v, G[ni][nj]);
                    if(G[ni][nj] >= G[i][j]) {
                        ok = false;
                    }
                }
            }

            if(ok) {
                G[i][j] = max_v;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cout << G[i][j] << " \n"[j == M - 1];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
