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

    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<int> color(N * M + 1, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(color[A[i][j]] == 2) {
                continue;
            }
            bool adj = false;
            for(int d = 0; d < 4; d++) {
                int ni = i + DR[d];
                int nj = j + DC[d];
                if(ni >= 0 && nj >= 0 && ni < N && nj < M && A[ni][nj] == A[i][j]) {
                    adj = true;
                    break;
                }
            }
            if(adj) {
                color[A[i][j]] = 2;
            } else {
                color[A[i][j]] = 1;
            }
        }
    }

    int sum = 0;
    for(int i = 1; i <= N * M; i++) {
        sum += color[i];
    }
    
    int ans = sum;
    for(int i = 1; i <= N * M; i++) {
        ans = std::min(ans, sum - color[i]); 
    }

    std::cout << ans << '\n';
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
