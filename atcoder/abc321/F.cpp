#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

void run_case() {
    int Q, K;
    std::cin >> Q >> K;

    std::vector<int64_t> dp(K + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < Q; i++) {
        std::string S;
        std::cin >> S;
        
        int X;
        std::cin >> X;

        std::vector<int64_t> ndp(K + 1, 0);
        if(S == "+") {
            for(int i = 0; i <= K; i++) {
                ndp[i] = dp[i]; 
                if(i - X >= 0) {
                    ndp[i] += dp[i - X];
                    ndp[i] %= MOD;
                }
            }
        } else {
            for(int i = 0; i <= K; i++) {
                ndp[i] = dp[i];
                if(i - X >= 0) {
                    ndp[i] = (dp[i] - ndp[i - X] + MOD) % MOD;
                }
            }
        }

        std::swap(dp, ndp);
        std::cout << dp[K] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
