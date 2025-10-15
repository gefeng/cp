#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N, C;
    std::cin >> N >> C;

    std::vector<int> B(N);
    std::vector<int> D(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> D[i];
    }

    std::vector<std::vector<int64_t>> best(N, std::vector<int64_t>(N, INF));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            best[i][j] = std::min(j == 0 ? best[i][j] : best[i][j - 1], static_cast<int64_t>(B[(i + j) % N]));
        }
    }

    int64_t ans = INF;
    for(int t = 0; t < N; t++) {
        int64_t cost = static_cast<int64_t>(t) * C;
        for(int i = 0; i < N; i++) {
            int64_t c = best[i][t];
            int64_t x = D[(i + t) % N];
            cost += x * c;
        }
        ans = std::min(ans, cost);
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
