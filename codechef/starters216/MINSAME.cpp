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
    int N, K;
    std::cin >> N >> K;

    std::vector<int64_t> fact(K + 1, 1);
    fact[0] = K;
    for(int i = 1, j = K - 1; i <= K; i++, j--) {
        fact[i] = j == 0 ? 1 : fact[i - 1] * j % MOD;
    }

    int64_t ans = 0;
    int64_t pre = K >= N ? fact[N - 1] : 0;
    
    for(int d = N - 1; d >= 1; d--) {
        if(d <= K) {
            int64_t c = fact[d - 1] * q_pow(K - d + 1, N - d) % MOD; 
            ans += ((c - pre + MOD) % MOD) * d % MOD;
            ans %= MOD;
            pre = c;
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
