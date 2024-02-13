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
    std::array<int, 4> A;
    int n = 0;
    for(int i = 0; i < 4; i++) {
        std::cin >> A[i];
        n += A[i];
    }

    if(std::abs(A[0] - A[1]) > 1) {
        std::cout << 0 << '\n';
        return;
    }

    if(A[0] == 0 && A[1] == 0) {
        if(A[2] && A[3]) {
            std::cout << 0 << '\n';
        } else {
            std::cout << 1 << '\n';
        }
        return;
    }

    std::vector<int64_t> fact(n + 1, 1);
    std::vector<int64_t> invf(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int64_t ans = 0;
    
    // start with 1
    // loop over how many shape 4 appears before the first shape 1
    if(A[0] && A[1] <= A[0]) {
        if(A[1]) {
            for(int i = 0; i <= A[3]; i++) {
                int64_t x = (fact[A[0] + A[2] - 1] * invf[A[2]] % MOD) * invf[A[0] - 1] % MOD;
                int64_t y = (fact[A[1] + A[3] - i - 1] * invf[A[3] - i] % MOD) * invf[A[1] - 1] % MOD;
                ans += x * y % MOD;
                ans %= MOD;
            }
        } else {
            int64_t x = (fact[A[0] + A[2] - 1] * invf[A[2]] % MOD) * invf[A[0] - 1] % MOD;
            ans += x;
            ans %= MOD;
        }
    }

    // start with 2
    // loop over how many shape 3 appears before the first shape 2
    if(A[1] && A[0] <= A[1]) {
        if(A[0]) {
            for(int i = 0; i <= A[2]; i++) {
                int64_t x = (fact[A[0] + A[2] - i - 1] * invf[A[2] - i] % MOD) * invf[A[0] - 1] % MOD;
                int64_t y = (fact[A[1] + A[3] - 1] * invf[A[3]] % MOD) * invf[A[1] - 1] % MOD;
                ans += x * y % MOD;
                ans %= MOD;
            }
        } else {
            int64_t x = (fact[A[1] + A[3] - 1] * invf[A[3]] % MOD) * invf[A[1] - 1] % MOD;
            ans += x;
            ans %= MOD;
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
