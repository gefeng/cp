#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

constexpr int64_t MAX = static_cast<int64_t>(1e5);

void run_case() {
    int64_t N;
    int M;
    std::cin >> N >> M;

    std::vector<std::pair<int64_t, int64_t>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    auto cmp = [](const auto& a, const auto& b) {
        return b.second * a.first < a.second * b.first;
    };

    std::ranges::sort(A, cmp);

    int64_t ans = 0;
    int64_t t = (std::max(static_cast<int64_t>(0), (N - MAX + 1)) + A[0].first - A[0].second - 1) / (A[0].first - A[0].second);
    
    ans += A[0].first * t;
    N -= t * (A[0].first - A[0].second);

    std::ranges::sort(A);
    std::vector<std::pair<int64_t, int64_t>> a;
    for(int i = 0; i < M; ) {
        int j = i;
        while(i < M && A[i].first == A[j].first) {
            i += 1;
        }
        a.emplace_back(A[i - 1].first, A[i - 1].second);
    }

    int n = a.size();
    std::vector<int64_t> dp(N + 1, -1);

    for(int i = 0; i <= N; i++) {
        dp[i] = i;
    }

    for(int i = 0; i < n; i++) {
        auto [x, y] = a[i];
        for(int j = 1; j <= N; j++) {
            if(j >= x) {
                dp[j] = std::max(dp[j], dp[j - x + y] + x);
            }
        }
    } 
    
    ans += dp[N];

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
