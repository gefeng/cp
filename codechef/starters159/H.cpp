#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t MOD = int64_t(1e9) + 7;

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
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int64_t> fact(M + 1, 1);
    std::vector<int64_t> invf(M + 1, 1);
    
    for(int i = 1; i <= M; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t inv2 = q_pow(2, MOD - 2);
    int64_t res = 0;
    for(int i = 1; i <= M; i++) {
        if(i >= N) {
            int64_t comb = (fact[i - 1] * invf[N - 1] % MOD) * invf[i - N] % MOD;
            res += q_pow(inv2, i) * comb % MOD; 
            res %= MOD;
        }
        std::cout << res << " \n"[i == M];
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
