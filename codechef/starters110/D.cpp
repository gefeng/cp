#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;
constexpr int MAX = (int)1e5;

std::vector<std::vector<int64_t>> dp(2, std::vector<int64_t>(MAX + 10, 0));

void run_case() {
    int L;
    std::cin >> L;

    int64_t ans = 0;
    int l = std::max(0, L - 4);
    int r = std::max(0, L - 1);
    for(int i = l; i <= r; i++) {
        ans += dp[0][i];
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    // (who, cleared_line) 
    dp[0][0] = 1;
    for(int i = 0; i <= MAX; i++) {
        for(int t = 0; t < 2; t++) {
            dp[t ^ 1][i + 1] += dp[t][i];
            dp[t ^ 1][i + 1] %= MOD;

            dp[t][i + 2] += dp[t][i];
            dp[t][i + 2] %= MOD;

            dp[t][i + 3] += dp[t][i];
            dp[t][i + 3] %= MOD;

            dp[t][i + 4] += dp[t][i];
            dp[t][i + 4] %= MOD;
        }
    }

    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
