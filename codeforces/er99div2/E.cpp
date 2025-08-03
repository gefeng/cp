#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t INF = static_cast<int64_t>(2e18);
constexpr int64_t MAX = static_cast<int64_t>(1e10);

void run_case() {
    std::vector<int64_t> X(4, 0);
    std::vector<int64_t> Y(4, 0);
    
    for(int i = 0; i < 4; i++) {
        std::cin >> X[i] >> Y[i];
    }

    auto solve = [&](const std::array<int, 4>& p, int64_t k) {
        int64_t min_d = 0;
        std::array<int64_t, 4> x;
        std::array<int64_t, 4> y;
        x[0] = X[p[0]];
        x[1] = X[p[1]] - k;
        x[2] = X[p[2]] - k;
        x[3] = X[p[3]];
        
        y[0] = Y[p[0]] - k;
        y[1] = Y[p[1]] - k;
        y[2] = Y[p[2]];
        y[3] = Y[p[3]];

        std::ranges::sort(x);
        std::ranges::sort(y);

        for(int i = 0; i < 4; i++) {
            min_d += std::abs(x[i] - x[1]) + std::abs(y[i] - y[1]);
        }

        return min_d;
    };

    int64_t ans = INF;

    std::array<int, 4> p = {0, 1, 2, 3};
    do {
        int64_t lo = 0;
        int64_t hi = MAX;
        while(hi - lo >= 3) {
            int64_t m1 = lo + (hi - lo) / 3;
            int64_t m2 = hi - (hi - lo) / 3;
            
            int64_t d1 = solve(p, m1);
            int64_t d2 = solve(p, m2);

            if(d1 < d2) {
                hi = m2;
            } else {
                lo = m1;
            }
        }
        for(int64_t i = lo; i <= hi; i++) {
            ans = std::min(ans, solve(p, i));
        }
    } while(std::next_permutation(p.begin(), p.end()));

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
