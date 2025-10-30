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
    int M;
    std::cin >> M;

    std::vector<int64_t> fact(M * 2 + 1, 1);
    std::vector<int64_t> invf(M * 2 + 1, 1);
    
    for(int i = 1; i <= M * 2; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }
    
    for(int n = 1; n <= M; n++) {
        int64_t res = 0;
        for(int k = 1; k <= M / (n + 1); k++) {
            int x = M - (n + 1) * k;
            res += (fact[x + n] * invf[n] % MOD) * invf[x] % MOD;
            res %= MOD;
        }
        res *= fact[n];
        res %= MOD;
        std::cout << res << " \n"[n == M];
    }
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
