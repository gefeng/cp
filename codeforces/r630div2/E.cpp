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
    int64_t N, M, L, R;
    std::cin >> N >> M >> L >> R;

    int64_t n = N * M;
    int64_t k = R - L;

    int64_t ans = q_pow(k + 1, n);

    if(n % 2 == 0) {
        if(k % 2 == 0) {
            ans += 1;
            ans %= MOD;
        }
        ans *= q_pow(2, MOD - 2);
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
