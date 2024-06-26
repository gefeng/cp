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
    int N, M, K, X, Y;
    std::cin >> N >> M >> K >> X >> Y;
    
    K = std::min(N, K);
    int64_t p = (int64_t)X * q_pow(Y, MOD - 2) % MOD;
    
    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t ans = 0;
    for(int s = 1; s <= K; s++) {
        int64_t a = (fact[N] * invf[s] % MOD) * invf[N - s] % MOD;
        int64_t b = q_pow((1 - (2 * p % MOD) + MOD) % MOD, s);
        b = (b + 1) % MOD;
        b = b * q_pow(2, MOD - 2) % MOD;
        b = q_pow(b, M);
        ans += a * b % MOD;
        ans %= MOD;
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
