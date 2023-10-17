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
    int64_t A, B;
    std::cin >> A >> B;

    int64_t cnt_d = 1;
    int64_t x = A;
    for(int64_t f = 2; f * f <= x; f++) {
        if(x % f == 0) {
            int64_t cnt = 0;
            while(x % f == 0) {
                x /= f;
                cnt += 1;
            }

            cnt_d *= ((cnt * (B % MOD) % MOD) + 1) % MOD;
            cnt_d %= MOD;
        }
    } 

    if(x > 1) {
        cnt_d *= ((B % MOD) + 1) % MOD;
        cnt_d %= MOD;
    }
    
    int64_t inv2 = q_pow(2, MOD - 2);

    int64_t ans = 0;
    if(B % 2 == 0) {
        ans = (((((cnt_d - 1 + MOD) % MOD) * (B % MOD) % MOD) * inv2 % MOD) + ((B % MOD) * inv2 % MOD)) % MOD;
    } else {
        int64_t sqr = (int64_t)sqrt(A);
        if(sqr * sqr == A) {
            ans = (((((cnt_d - 1 + MOD) % MOD) * (B % MOD) % MOD) * inv2 % MOD) + ((((B % MOD) - 1 + MOD) % MOD) * inv2 % MOD)) % MOD;
        } else {
            ans = (cnt_d * inv2 % MOD) * (B % MOD) % MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
