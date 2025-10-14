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

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto solve = [&]() {
        std::vector<int64_t> dp(N + 1, INF); 
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i < N; i++) {
            dp[i] = std::min(dp[i], dp[i - 2] + std::abs(A[i - 1] - A[i - 2]));
            if(i - 3 >= 0) {
                std::array<int, 3> a = {A[i - 1], A[i - 2], A[i - 3]};
                std::ranges::sort(a);
                dp[i] = std::min(dp[i], dp[i - 3] + a[1] - a[0] + a[2] - a[1]);
            }
        }

        dp[N] = dp[N - 1] + std::abs(A[0] - A.back());
        std::array<int, 3> a = {A[N - 2], A[N - 1], A[0]};
        std::ranges::sort(a);
        dp[N] = std::min(dp[N], dp[N - 2] + a[1] - a[0] + a[2] - a[1]);
        
        return dp[N];
    };

    int64_t ans = INF;
    for(int _ = 0; _ < 6; _++) {
        ans = std::min(ans, solve());
        int pre = A.back();
        for(int i = 0; i < N; i++) {
            int tmp = A[i];
            A[i] = pre;
            pre = tmp;
        }
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
