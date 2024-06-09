#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = (int64_t)998244353;

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
    int64_t N;
    std::cin >> N;

    int64_t base = 1;
    int64_t x = N;
    while(x) {
        base *= 10;
        base %= MOD;
        x /= 10;
    }
    
    int64_t ans = (N % MOD) * ((1 - q_pow(base, N) + MOD) % MOD) % MOD;
    ans *= q_pow((1 - base + MOD) % MOD, MOD - 2);
    ans %= MOD;

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
