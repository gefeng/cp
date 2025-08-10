#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <ranges>

void run_case() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<std::pair<int, int>> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i].first >> A[i].second;
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x.first + x.second < y.first + y.second;
            });

    auto count = [&](int l1, int r1, int l2, int r2) {
        if(l1 > l2) {
            std::swap(l1, l2);
            std::swap(r1, r2);
        }
        
        if(r1 < l2) {
            return 0;
        }
    
        return std::min(r1, r2) - std::max(l1, l2) + 1;
    };

    int ans = 0;
    std::vector<int> dp(M + 1, 0);
    for(int i = 1; i <= N - K + 1; i++) {
        int r = i + K - 1;
        int cnt = 0;
        for(int j = M - 1; j >= 0; j--) {
            cnt += count(i, r, A[j].first, A[j].second);
            dp[M - j] = std::max(dp[M - j], cnt);
        }
    }

    ans = dp[M];

    for(int i = 1; i <= N - K + 1; i++) {
        int r = i + K - 1;
        int cnt = 0;
        for(int j = 0; j < M; j++) {
            cnt += count(i, r, A[j].first, A[j].second);
            ans = std::max(ans, cnt + dp[M - j - 1]);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
