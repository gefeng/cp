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
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x.first - x.second < y.first - y.second;
            });

    int64_t ans = 0;
    int64_t sum_b = 0;
    for(int i = 0; i < N; i++) {
        ans += A[i].first;
        sum_b += A[i].second;
    }

    int64_t min_v = INF;
    int64_t prefix = 0;
    for(int i = 0; i < N; i++) {
        min_v = std::min(min_v, static_cast<int64_t>(A[i].first));
        prefix += A[i].first;
        sum_b -= A[i].second;
    
        int need = std::max(0, N - 1 - i - (i + 1));
        int64_t cost = prefix + need * min_v + sum_b;

        ans = std::min(ans, cost);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
