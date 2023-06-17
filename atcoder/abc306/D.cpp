#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

constexpr LL INF = (LL)2e18;

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    std::vector<int> B(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<std::vector<LL>> dp(N + 1, std::vector<LL>(2, 0LL));

    for(int i = 1; i <= N; i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];

        if(A[i - 1] == 0) {
            dp[i][0] = std::max(dp[i][0], dp[i - 1][0] + B[i - 1]);
            dp[i][0] = std::max(dp[i][0], dp[i - 1][1] + B[i - 1]);
        } else {
            dp[i][1] = std::max(dp[i][1], dp[i - 1][0] + B[i - 1]);
        }
    }

    LL ans = std::max(dp[N][0], dp[N][1]);
    
    if(ans == -INF) {
        ans = 0LL;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
