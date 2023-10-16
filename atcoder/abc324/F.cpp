#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>

constexpr double INF = 2e14;
constexpr double EPS = 1e-9;

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<std::array<int, 3>>> G(N);
    for(int i = 0; i < M; i++) {
        int U, V, B, C;
        std::cin >> U >> V >> B >> C;
        U -= 1;
        V -= 1;
        G[U].push_back({V, B, C});
    }

    double lo = 0.0;
    double hi = 2e9;
    double ans = 0.0;
    while(hi - lo >= EPS) {
        double mid = (lo + hi) / 2.0;
    
        std::vector<double> dp(N, -INF);
        dp[0] = 0.0;
        for(int i = 0; i < N - 1; i++) {
            for(auto nei : G[i]) {
                dp[nei[0]] = std::max(dp[nei[0]], dp[i] + nei[1] - mid * nei[2]);
            } 
        }

        if(dp[N - 1] >= EPS) {
            ans = mid;
            lo = mid;
        } else {
            hi = mid;
        }
    }

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
