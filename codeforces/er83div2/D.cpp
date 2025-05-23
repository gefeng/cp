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
    int N, M;
    std::cin >> N >> M;

    std::vector<int64_t> fact(M + 1, 1);
    std::vector<int64_t> invf(M + 1, 1);
    
    for(int i = 1; i <= M; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }
    
    int64_t ans = 0;
    for(int p = 1; p <= M; p++) {
        if(p - 1 >= N - 2) {
            int64_t cnt = (fact[p - 1] * invf[N - 2] % MOD) * invf[p - 1 - N + 2] % MOD;
            cnt *= N - 2;
            cnt %= MOD;
            cnt *= q_pow(2, N - 2);
            cnt %= MOD;
            cnt *= q_pow(2, MOD - 2);
            ans += cnt;
            ans %= MOD;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
