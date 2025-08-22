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
    
    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    std::array<int, 3> cnt = {};
    for(int i = 1; i <= N; i++) {
        cnt[i % 3] += 1;
    }

    if(cnt[0] == 0) {
        std::cout << 0 << '\n';
        return;
    }

    auto solve = [&](int s) {
        int64_t res = 0;
        for(int x = 1; x < s; x++) {
            int y = s - x;
            if(cnt[1] < x || cnt[2] < y) {
                continue;
            }

            int64_t arrange = (fact[x + y] * invf[x] % MOD) * invf[y] % MOD;
            int64_t one = (fact[cnt[1] - 1] * invf[x - 1] % MOD) * invf[cnt[1] - x] % MOD;
            int64_t two = (fact[cnt[2] - 1] * invf[y - 1] % MOD) * invf[cnt[2] - y] % MOD;
            res += (one * two % MOD) * arrange % MOD;
            res %= MOD;
        } 
        return res;
    };

    int64_t ans = solve(cnt[0]) * 2 % MOD;
    ans += solve(cnt[0] + 1);
    ans %= MOD;
    ans += solve(cnt[0] - 1);
    ans %= MOD;

    for(int i = 0; i < 3; i++) {
        ans *= fact[cnt[i]];
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
