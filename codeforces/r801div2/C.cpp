#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <tuple>
#include <queue>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> A(N, std::vector<int>(M, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            std::cin >> A[i][j];
        }
    }

    int n = N + M - 1;
    if(n % 2 == 1) {
        std::cout << "NO" << '\n';
        return;
    }

    std::vector<std::vector<int>> dp1(N, std::vector<int>(M, -INF));
    std::vector<std::vector<int>> dp2(N, std::vector<int>(M, INF));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == 0 && j == 0) {
                dp1[i][j] = A[i][j];
                dp2[i][j] = A[i][j];
            }
            if(i) {
                dp1[i][j] = std::max(dp1[i][j], dp1[i - 1][j] + A[i][j]);
                dp2[i][j] = std::min(dp2[i][j], dp2[i - 1][j] + A[i][j]);
            }
            if(j) {
                dp1[i][j] = std::max(dp1[i][j], dp1[i][j - 1] + A[i][j]);
                dp2[i][j] = std::min(dp2[i][j], dp2[i][j - 1] + A[i][j]);
            }
        }
    }

    std::cout << (dp1[N - 1][M - 1] >= 0 && dp2[N - 1][M - 1] <= 0 ? "YES" : "NO") << '\n';
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
