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
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    int n = A + B + C + D;
    
    std::vector<int64_t> fact(n + 1, 1);
    std::vector<int64_t> invf(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }
    
    int64_t ans = 0;
    for(int i = A + B + 1; i <= n + 1 - D; i++) {
        // i is first position of D
        int64_t cnt = (fact[n - i] * invf[D - 1] % MOD) * invf[n - i - D + 1] % MOD;
        cnt *= (fact[i - 1] * invf[B] % MOD) * invf[i - 1 - B] % MOD;
        cnt %= MOD;
        
        ans += cnt;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
