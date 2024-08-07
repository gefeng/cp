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
    dp[N] = 1;
    
    int64_t sum = 0;
    for(int i = N; i > 0; i--) {
        if(i == N) {
            dp[i] = 1;
        } else {
            dp[i] += sum;
            dp[i] %= MOD;
        }

        if(i > 1) {
            for(int l = 2; l <= i; ) {
                int r = i / (i / l);
                dp[i / l] += dp[i] * (r - l + 1) % MOD;
                dp[i / l] %= MOD;
                l = r + 1;
            }    
        }

        sum += dp[i];
        sum %= MOD;
    }
    
    std::cout << dp[1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
