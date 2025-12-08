#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>
#include <numeric>

constexpr int MAX = static_cast<int>(1e9);
constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int ans = 0;

    auto solve1 = [&](std::vector<int> a) {
        std::vector<int> order(N);
        std::iota(order.begin(), order.end(), 0);

        std::ranges::sort(order, [&](int i, int j) {
                    return a[i] < a[j];
                });
        
        for(int i = 0; i < K; i++) {
            a[order[i]] = MAX;
        }

        std::vector<int> min_r(N, INF);
        for(int i = N - 2; i >= 0; i--) {
            min_r[i] = std::min(a[i + 1], min_r[i + 1]);
        }

        int min_l = INF;
        for(int i = 0; i < N - 1; i++) {
            int min1 = std::min(min_l, min_r[i + 1]);
            int min2 = std::min(a[i], a[i + 1]);

            if(static_cast<int64_t>(2) * min1 <= min2) {
                ans = std::max(ans, 2 * min1); 
            } else {
                ans = std::max(ans, min2);
            }
            min_l = std::min(min_l, a[i]);
        }
    };

    auto solve2 = [&](std::vector<int> a) {
        std::vector<int> order(N);
        std::iota(order.begin(), order.end(), 0);

        std::ranges::sort(order, [&](int i, int j) {
                    return a[i] < a[j];
                });
        
        for(int i = 0; i < K - 1; i++) {
            a[order[i]] = MAX;
        }

        std::vector<int> min_r(N, INF);
        for(int i = N - 2; i >= 0; i--) {
            min_r[i] = std::min(a[i + 1], min_r[i + 1]);
        }

        int min_l = INF;
        for(int i = 0; i < N - 1; i++) {
            int min1 = std::min(min_l, min_r[i + 1]);
            int min2 = std::max(a[i], a[i + 1]);

            if(static_cast<int64_t>(2) * min1 <= min2) {
                ans = std::max(ans, 2 * min1); 
            } else {
                ans = std::max(ans, min2);
            }
            min_l = std::min(min_l, a[i]);
        }
    };

    auto solve3 = [&](std::vector<int> a) {
        std::vector<int> order(N);
        std::iota(order.begin(), order.end(), 0);

        std::ranges::sort(order, [&](int i, int j) {
                    return a[i] < a[j];
                });
        
        for(int i = 0; i < K - 2; i++) {
            a[order[i]] = MAX;
        }

        std::vector<int> min_r(N, INF);
        for(int i = N - 2; i >= 0; i--) {
            min_r[i] = std::min(a[i + 1], min_r[i + 1]);
        }

        int min_l = INF;
        for(int i = 0; i < N - 1; i++) {
            int min1 = std::min(min_l, min_r[i + 1]);
            int min2 = MAX;

            if(static_cast<int64_t>(2) * min1 <= min2) {
                ans = std::max(ans, 2 * min1); 
            } else {
                ans = std::max(ans, min2);
            }
            min_l = std::min(min_l, a[i]);
        }
    };

    solve1(A);
    solve2(A);
    if(K > 1) {
        solve3(A);
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
