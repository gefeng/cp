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
    int N, K;
    std::cin >> N >> K;

    if(N < K) {
        std::cout << 0 << '\n';
        return;
    }

    if(K == 1) {
        std::cout << N << '\n';
        return;
    }

    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    std::vector<int> cnt_mul(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j += i) {
            cnt_mul[i] += 1;
        }
    }

    int64_t ans = (fact[N - 1] * invf[K - 1] % MOD) * invf[N - K] % MOD;
    
    for(int i = 2; i <= N; i++) {
        int tot = cnt_mul[i] - 1;
        if(tot >= K - 1) {
            ans += (fact[tot] * invf[K - 1] % MOD) * invf[tot - K + 1] % MOD;
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
