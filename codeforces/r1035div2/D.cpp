#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    int64_t M;
    std::cin >> N >> M;

    std::vector<int64_t> dp(N + 1, 0);
    dp[0] = 1;
    
    int64_t ans = 0;
    for(int i = N; i >= 1; i--) {
        std::vector<int64_t> n_dp(N + 1, 0);

        for(int j = 0; j <= N - i; j++) {
            int64_t cnt_pos = N - i + 1 - j;
            n_dp[j + 1] += (cnt_pos * dp[j] % M) * i;
            n_dp[j + 1] %= M;
            n_dp[j] += dp[j];
            n_dp[j] %= M;
        }

        dp = std::move(n_dp);
    }

    for(int i = 0; i <= N; i++) {
        ans += dp[i];
        ans %= M;
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
