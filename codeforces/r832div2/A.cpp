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

constexpr int64_t INF = static_cast<int64_t>(2e18);

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::ranges::sort(A);

    int64_t sum1 = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
    int64_t sum2 = 0;
    int64_t ans = -INF; 
    for(int i = 0; i < N; i++) {
        sum1 -= A[i];
        sum2 += A[i];
        ans = std::max(ans, std::abs(sum1) - std::abs(sum2));
        ans = std::max(ans, std::abs(sum2) - std::abs(sum1));
    }

    sum1 = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
    sum2 = 0;
    for(int i = N - 1; i >= 0; i--) {
        sum1 -= A[i];
        sum2 += A[i];
        ans = std::max(ans, std::abs(sum1) - std::abs(sum2));
        ans = std::max(ans, std::abs(sum2) - std::abs(sum1));
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
