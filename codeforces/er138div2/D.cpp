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
    int64_t M;
    std::cin >> N >> M;

    std::vector<int64_t> dp(N + 1, 0);
    std::vector<int> is_prime(N + 1, 1);
    int64_t now = 1;
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i + i; j <= N; j += i) {
                is_prime[j] = 0;
            }
            if(now <= M / i) {
                now *= i;
            } else {
                break;
            }
        }
        dp[i] = M / now;
        dp[i] %= MOD;
    }

    M %= MOD;
    int64_t ans = 0;
    int64_t tot = M;
    int64_t bad = 1;
    for(int i = 2; i <= N; i++) {
        bad *= dp[i];
        bad %= MOD;
        int64_t cnt = M * bad % MOD;

        tot *= M;
        tot %= MOD;
        
        ans += (tot - cnt + MOD) % MOD;
        ans %= MOD;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
