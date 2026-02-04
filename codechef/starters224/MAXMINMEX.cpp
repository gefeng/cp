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
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }


    std::ranges::sort(A);
    
    std::vector<int64_t> fact(N + 1, 1);
    std::vector<int64_t> invf(N + 1, 1);
    for(int i = 1; i <= N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        invf[i] = q_pow(fact[i], MOD - 2);
    }

    int max_len = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int j = i;
        while(i + 1 < N && A[i + 1] - A[i] == 1) {
            i += 1;
        }
        int len = i - j + 1;
        if(len == max_len) {
            cnt += 1;
        } else if(len > max_len) {
            max_len = len;
            cnt = 1;
        }
    }

    int64_t ans = 0;
    for(int prefix = 0; prefix <= max_len; prefix++) {
        ans += (fact[max_len] * invf[prefix] % MOD) * invf[max_len - prefix] % MOD;
        ans %= MOD;
    }

    ans *= q_pow(2, MOD - 2);
    ans %= MOD;
    ans *= cnt;
    ans %= MOD;
    
    for(int i = N - max_len; i >= 1; i--) {
        ans *= i;
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
