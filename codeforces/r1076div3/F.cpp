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
    int N, SX, SY, TX, TY;
    std::cin >> N >> SX >> SY >> TX >> TY;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first;
    }

    for(int i = 0; i < N; i++) {
        std::cin >> A[i].second;
    }

    std::ranges::sort(A);

    std::vector<std::tuple<int, int, int, int>> a;
    
    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && A[i].first == A[j].first) {
            i += 1;
        }

        a.emplace_back(A[j].first, A[j].second, A[i - 1].first, A[i - 1].second);
    }

    auto dist = [](int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
        return std::abs(x1 - x2) + std::abs(y1 - y2);
    };

    int n = a.size();
    std::vector<int64_t> dp(2, INF);
    dp[0] = dist(SX, SY, std::get<0>(a[0]), std::get<1>(a[0])) + std::get<3>(a[0]) - std::get<1>(a[0]);
    dp[1] = dist(SX, SY, std::get<2>(a[0]), std::get<3>(a[0])) + std::get<3>(a[0]) - std::get<1>(a[0]);
    
    for(int i = 1; i < n; i++) {
        auto [x1, y1, _, y2] = a[i];
        auto [x2, b1, __, b2] = a[i - 1];
        std::vector<int64_t> ndp(2, INF);
        
        ndp[0] = std::min(ndp[0], dp[0] + dist(x2, b2, x1, y1) + y2 - y1);
        ndp[1] = std::min(ndp[1], dp[0] + dist(x2, b2, x1, y2) + y2 - y1);

        ndp[0] = std::min(ndp[0], dp[1] + dist(x2, b1, x1, y1) + y2 - y1);
        ndp[1] = std::min(ndp[1], dp[1] + dist(x2, b1, x1, y2) + y2 - y1);

        dp = std::move(ndp);
    }
    
    int64_t ans = 0;
    {
        auto [x, y1, _, y2] = a.back();
        ans = std::min(dp[1] + dist(x, y1, TX, TY), dp[0] + dist(x, y2, TX, TY)); 
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
