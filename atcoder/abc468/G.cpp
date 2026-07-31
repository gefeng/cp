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
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    if(S[0] == 'x' || S.back() == 'x') {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int64_t> fact(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    
    std::vector<int64_t> dp(N + 1, 0);    
    dp[2] = 2;
    for(int i = 3; i <= N; i++) {
        dp[i] = fact[i];
        for(int j = 2; j < i; j++) {
            dp[i] -= dp[j] * fact[i - j + 1] % MOD; 
            dp[i] += MOD;
            dp[i] %= MOD;
        }
    }

    int pre = -1;
    int64_t ans = 1;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'o') {
            if(pre != -1) {
                ans *= dp[i - pre + 1];
                ans %= MOD;
            }
            pre = i;
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
