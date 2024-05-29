#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t K, SX, SY, TX, TY;
    std::cin >> K >> SX >> SY >> TX >> TY;
    
    if(K == 1) {
        std::cout << std::abs(SX - TX) + std::abs(SY - TY) << '\n';
        return;
    }

    auto get_adj_large = [&](int64_t x, int64_t y) {
        std::vector<std::array<int64_t, 3>> adj;
        if((x / K + y / K) % 2 != 0) {
            adj.push_back({x / K + y / K, x / K - y / K, 0});
        } else {
            int64_t d_l = (x % K) + 1;
            int64_t d_r = K - (x % K);
            int64_t d_u = K - (y % K);
            int64_t d_d = (y % K) + 1;
        
            x /= K;
            y /= K;
            adj.push_back({x - 1 + y, x - 1 - y, d_l});
            adj.push_back({x + 1 + y, x + 1 - y, d_r});
            adj.push_back({x + y + 1, x - y - 1, d_u});
            adj.push_back({x + y - 1, x - y + 1, d_d});
        }
        return adj;
    };

    auto dist = [&](int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
        int64_t dx = std::abs(x1 - x2);
        int64_t dy = std::abs(y1 - y2);
        if(K > 2) {
            return dx + dy;
        }
        return dx + dy - std::min(dx, dy) / 2;
    };

    int64_t ans = std::abs(SX - TX) + std::abs(SY - TY);
    std::vector<std::array<int64_t, 3>> s = get_adj_large(SX, SY);
    std::vector<std::array<int64_t, 3>> t = get_adj_large(TX, TY);

    for(auto& a : s) {
        for(auto& b : t) {
            ans = std::min(ans, dist(a[0], a[1], b[0], b[1]) + a[2] + b[2]);
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
