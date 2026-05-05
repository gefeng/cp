#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

void run_case() {
    std::string S;
    std::cin >> S;

    int n = S.size();
    int64_t ans = 0;

    std::vector<int64_t> dp(3, 0);
    dp[S[0] - 'a'] = 1;

    for(int i = 1; i < n; i++) {
        std::vector<int64_t> ndp(dp);
        
        for(int j = 0; j < 3; j++) {
            if(S[i] - 'a' == j) {
                ndp[S[i] - 'a'] += 1;
                ndp[S[i] - 'a'] %= MOD;
            } else {
                ndp[S[i] - 'a'] += dp[j];
                ndp[S[i] - 'a'] %= MOD;
            }
        }

        dp = std::move(ndp);
    }

    for(int i = 0; i < 3; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
