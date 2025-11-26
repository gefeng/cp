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
    std::string S;
    std::cin >> S;

    int n = S.size();
    
    std::vector<int64_t> fact(n + 1, 1);
    std::vector<int64_t> invf(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t ans = 0;
    for(char c = '1'; c <= '9'; c++) {
        std::vector<int> suffix(n, 0);
        int c0 = 0;
        int c1 = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(S[i] == c) {
                suffix[i] = c1;
                c1 += 1;
            }
        }

        for(int i = 0; i < n; i++) {
            if(S[i] == c - 1) {
                c0 += 1;
                continue;
            }
            
            if(S[i] == c) {
                c1 = suffix[i];
                int d = std::min(c0, c1 + 1);
                // int64_t cnt = 0;
                // for(int j = 1; j <= d; j++) {
                //     int64_t x = (fact[c0] * invf[j] % MOD) * invf[c0 - j] % MOD;
                //     int64_t y = (fact[c1] * invf[j - 1] % MOD) * invf[c1 - j + 1] % MOD;
                //     cnt += x * y % MOD;
                //     cnt %= MOD;
                // }
                // ans += cnt;
                // ans %= MOD;

                if(c0) { 
                    int64_t cnt = (fact[c0 + c1] * invf[c0 - 1] % MOD) * invf[c1 + 1] % MOD;
                    ans += cnt;
                    ans %= MOD;
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
