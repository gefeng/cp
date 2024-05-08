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
    int N, M;
    std::cin >> N >> M;

    if(M == 1) {
        std::cout << 1 << '\n';
        return;
    }

    std::vector<int64_t> fact(std::max(N, M) + 1, 1);
    std::vector<int64_t> invf(std::max(N, M) + 1, 1);
    for(int i = 2; i <= std::max(N, M); i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t ans = 0;
    int64_t prefix = 1;
    for(int i = 1; i <= std::min(N, M); i++) {
        prefix *= M - (i - 1); 
        prefix %= MOD;
        
        int suffix_len = N - i;
        int cnt = suffix_len / i;
        int rem = suffix_len % i;

        int64_t x = prefix;
        if(cnt) {
            x *= q_pow(fact[i], cnt);
            x %= MOD;
        }

        if(rem) {
            x *= fact[i] * invf[i - rem] % MOD;
            x %= MOD;
        }

        ans += x;
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
