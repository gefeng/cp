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
    int64_t MOD;
    std::cin >> N >> MOD;

    std::vector<int64_t> dp(N + 1, 0);
    std::vector<int64_t> jump(N + 1, 0);
    dp[1] = 1;
    
    int64_t sum = 1;
    for(int i = 2; i <= N; i++) {
        dp[i] += sum % MOD;
        dp[i] %= MOD;

        jump[i] += (jump[i - 1] + 1) % MOD;

        dp[i] += jump[i] % MOD;
        dp[i] %= MOD;

        for(int j = i + i; j <= N; j += i) {
            jump[j] -= dp[i - 1];
            jump[j] += MOD;
            jump[j] %= MOD;
            
            jump[j] += dp[i];
            jump[j] %= MOD;
        }

        sum += dp[i];
        sum %= MOD;
    }

    std::cout << dp[N] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    run_case();
}
