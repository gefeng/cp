#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)1e9 + 7;

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
    int L, R, K;
    std::cin >> L >> R >> K;
    
    if(K >= 10) {
        std::cout << 0 << '\n';
        return;
    }

    if(K == 1) {
        std::cout << (q_pow(10, R) - q_pow(10, L) + MOD) % MOD << '\n';
        return;
    }

    int64_t d = 9 / K;
    int64_t ans = (1 - q_pow(d + 1, R - L) + MOD) % MOD;
    ans *= q_pow((MOD - d) % MOD, MOD - 2);
    ans %= MOD;
    
    ans *= d * q_pow(d + 1, L) % MOD;
    ans %= MOD;

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
