#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = static_cast<int64_t>(998244353);

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
    
    if(N == 2) {
        std::cout << 1 << ' ' << 0 << ' ' << 1 << '\n';
        return;
    }
    
    
    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t a = 0;
    int64_t b = 0;
    for(int i = 0, m = N, n = N / 2; i < N / 2; i++, m -= 2, n -= 1) {
        if(i % 2 == 0) {
            a += (fact[m - 1] * invf[n - 1] % MOD) * invf[m - n] % MOD;
            a %= MOD;
        } else {
            if(n - 2 >= 0) {
                a += (fact[m - 2] * invf[n - 2] % MOD) * invf[m - n] % MOD;
                a %= MOD;
            }
        }
    }
    b = (((fact[N] * invf[N / 2] % MOD) * invf[N / 2] % MOD) - a + MOD) % MOD;
    b = (b - 1 + MOD) % MOD;

    std::cout << a << ' ' << b << ' ' << 1 << '\n';
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
