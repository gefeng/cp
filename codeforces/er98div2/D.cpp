#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(998244353);

int64_t q_pow(int64_t x, int64_t y) {
    int64_t res = 1;
    while(y) {
        if(y & 1) {
            res *= x;
            res %= MOD;
        }
        x *= x;
        x %= MOD;
        y >>= 1;
    }
    return res;
}

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int64_t> dp(N + 1, 0); 
    std::vector<int64_t> ds(2, 0);
    dp[0] = 1;
    int64_t p = q_pow(2, MOD - 2);
    for(int i = 1; i <= N; i++) {
        ds[(i - 1) % 2] += dp[i - 1];
        ds[(i - 1) % 2] %= MOD;
        dp[i] = ds[(i - 1) % 2] * p % MOD;
        for(int j = 0; j < 2; j++) {
            ds[j] *= p;
            ds[j] %= MOD;
        }
    }

    std::cout << dp[N] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
