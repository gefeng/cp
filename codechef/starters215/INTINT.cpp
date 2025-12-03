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

    std::vector<int64_t> A(N);
    std::vector<int64_t> B(N);
    
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }
    
    std::vector<int64_t> dp1(N, -INF);
    std::vector<int64_t> dp2(N, -INF);
    std::vector<int64_t> dp3(N, -INF);
    std::vector<int64_t> dp4(N, -INF);
    
    auto max_sum_l = [](std::vector<int64_t>& a, std::vector<int64_t>& dp) {
        int n = a.size();
        dp[0] = a[0];
        for(int i = 1; i < n; i++) {
            dp[i] = std::max(dp[i - 1] + a[i], a[i]);
        }
    };

    auto max_sum_r = [](std::vector<int64_t>& a, std::vector<int64_t>& dp) {
        int n = a.size();
        dp[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = std::max(dp[i + 1] + a[i], a[i]);
        }
    };

    max_sum_l(A, dp1);
    max_sum_r(A, dp2);
    max_sum_l(B, dp3);
    max_sum_r(B, dp4);

    int64_t ans = -INF;
    for(int i = 0; i < N; i++) {
        ans = std::max(ans, dp1[i] + dp2[i] - A[i] + dp3[i] + dp4[i] - B[i]);
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
