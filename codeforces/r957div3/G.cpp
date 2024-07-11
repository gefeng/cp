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
    int N;
    std::cin >> N;

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t ans = 0;
    for(int t = 0; t <= N; t++) {
        ans += ((fact[N] * invf[t] % MOD) * invf[N - t] % MOD) * (2 * t + 1) % MOD;
        ans %= MOD;
        

        if(t <= (N - 1) / 2) {
            for(int mex = t + 1; mex < 2 * t + 1; mex++) {
                int64_t x = (fact[mex - 1] * invf[t] % MOD) * invf[mex - 1 - t] % MOD;
                int64_t y = (fact[N - mex] * invf[2 * t + 1 - mex] % MOD) * invf[N - 2 * t - 1] % MOD;
                ans -= (x * y % MOD) * (2 * t + 1 - mex) % MOD;
                ans = (ans + MOD) % MOD;
            }
        }
    }

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
